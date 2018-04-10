//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MyThread.h"
#include "Unit1.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall MyThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
   static float log2(float x)
{
	float result = log(x)/log((float)2);
	return result;
}
__fastcall MyThread::MyThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall MyThread::Execute()
{
	//---- Place thread code here ----
	//ShowMessage("�������");
    FreeOnTerminate = true;

	int BPF = 65536;
	if(Form1->ComboBox1->ItemIndex==0)BPF = 16384;
	if(Form1->ComboBox1->ItemIndex==1)BPF = 32768;
	if(Form1->ComboBox1->ItemIndex==2)BPF = 65536;
	if(Form1->ComboBox1->ItemIndex==3)BPF = 131072;
	int order = (int)log2(BPF);
	int start = StrToInt(Form1->Edit3->Text);
	int end = StrToInt(Form1->Edit4->Text);


	// ������
	int iFileHandle = FileOpen(Form1->Edit1->Text, fmOpenRead);
	UnicodeString outFileName = Form1->Edit2->Text;
	if(iFileHandle<=0)
	{
		ShowMessage("������ �������� �������� �����");
		Form1->Button3->Enabled = true;
		return;
	}

	RggHeader fileHeader = {0};
	__int64 fileLength = (__int64)FileSeek(iFileHandle, (__int64)0,2);

	Form1->allBytes = fileLength;
	//������ �����
	FileSeek(iFileHandle, 0, 0);
	__int64 iBytesRead = FileRead(iFileHandle, &fileHeader, sizeof(RggHeader)); //��������� ��������� ����� �
	int sizeOfDataType;  //������ ��� � ������� ��������� ������
	if(fileHeader.format.typeSamples==0)sizeOfDataType=1;//char
	if(fileHeader.format.typeSamples==1)sizeOfDataType=2;//short
	if(fileHeader.format.typeSamples==2)sizeOfDataType=1;//uchar
	if(fileHeader.format.typeSamples==3)sizeOfDataType=2;//ushort
	if(fileHeader.format.typeSamples==4)sizeOfDataType=4;//float
	if(fileHeader.format.typeSamples==5)sizeOfDataType=8;//double

	__int64 FileLength = fileLength; ///�� ��� ����))
	__int64 countOfStr = (FileLength - sizeof(RggHeader))/(sizeof(RggStrHeader) + fileHeader.format.cntSamples*2*sizeOfDataType);
	//������ ���������� ����� �� ������� ���

	//ShowMessage((UnicodeString)"������ ���������� ����� �� �������: " + countOfStr);
	Form1->Label11->Caption = countOfStr;
	Form1->ProgressBar1->Max = countOfStr;
	Form1->ProgressBar1->Position = 0;

	int iNewFileHandle = FileCreate(Form1->Edit2->Text);
	FileClose(iNewFileHandle);
	FileSeek(iNewFileHandle, 0, 0);
	iNewFileHandle = FileOpen(Form1->Edit2->Text, fmOpenWrite);
	if(iNewFileHandle<=0)
	{
		ShowMessage("�� ������� ������� �������� ����");
			//ShowMessage(iNewFileHandle);
        //Form1->Button1->Enabled = true;
		return;
	}

    __int64 iBytesWrite = FileWrite(iNewFileHandle, &fileHeader, sizeof(RggHeader));
	Form1->WrBytes = iBytesWrite;

    if(iBytesRead!=iBytesWrite)ShowMessage("����������� ����� ��������� �����");

	//�� ������ ������

	for(int i = 0; i<countOfStr; i++)
	{

		RggStrHeader strHeader = {0};
		iBytesRead+=FileRead(iFileHandle, &strHeader, sizeof(RggStrHeader));
		Form1->strHeaderVec.push_back(strHeader);
		//��������� ���������
		//std::vector<Complex> vec;
		KStr str;
		iBytesRead+=FileRead(iFileHandle, &str, sizeof(KStr));
		Form1->in.push_back(str);
		Form1->ProgressBar1->Position = i;
		Form1->Label6->Caption = i;

	}
	//ShowMessage(Form1->strHeaderVec.size());
	//ShowMessage(sizeof(RggStrHeader));
	//ShowMessage(sizeof(KStr));
	//ShowMessage(sizeof(RggHeader));
	for(int i = countOfStr; i< BPF; i++)
	{
		 RggStrHeader strHeader = Form1->strHeaderVec[0];
		 Form1->strHeaderVec.push_back(strHeader);
		 KStr str = {0};
		 Form1->in.push_back(str);
		 Form1->Label6->Caption = i;

	}
	countOfStr =  BPF;
	Form1->ProgressBar2->Max = fileHeader.format.cntSamples;
	Form1->ProgressBar3->Max = countOfStr;

	FileClose(iFileHandle);
	//�������� ���� ������� ���� � ������, ������ ��������� � ��� ��������

	//Complex *Cmas = new Complex[countOfStr];
	//������ ���������� ����� ������������ �������
	for(int i =0; i<fileHeader.format.cntSamples; i++)
	{
		std::vector<Ipp32fc> ComplexVec(countOfStr);
		for(int j = 0; j<countOfStr; j++)
		{

			ComplexVec[j].re = Form1->in[j].mas[i].Re;
			ComplexVec[j].im = Form1->in[j].mas[i].Im;


		}




		IppStatus status;
		IppsFFTSpec_C_32fc* spec;
		status = ippsFFTInitAlloc_C_32fc(&spec, order,IPP_FFT_DIV_BY_SQRTN,ippAlgHintAccurate );
		status = ippsFFTFwd_CToC_32fc_I(&ComplexVec[0], spec, NULL );//Forward Transform
		for(int k = start ; k<end; k++)
		{
			ComplexVec[k].re =0;
			ComplexVec[k].im =0;
		}

		//������ �������� �������������� �����
		status = ippsFFTInv_CToC_32fc_I(&ComplexVec[0], spec, NULL );

		//������ ����������� ������ ������� �������� � ������
		for(int j = 0; j<countOfStr; j++)
		{

			Form1->in[j].mas[i].Re = ComplexVec[j].re;
			Form1->in[j].mas[i].Im = ComplexVec[j].im;

		}
		Form1->ProgressBar2->Position = i;
		Form1->Label7->Caption = i;
		//delete spec;
		status = ippsFFTFree_C_32fc(spec);

        ComplexVec.clear();
	}

	//��� ����������, �������� ��������
	for(int  i =0; i< countOfStr; i++)
	{

		RggStrHeader strHe = Form1->strHeaderVec[i];

		iBytesWrite+=FileWrite(iNewFileHandle, &strHe, sizeof(RggStrHeader));

		KStr str = Form1->in[i];
		iBytesWrite+=FileWrite(iNewFileHandle, &str, sizeof(KStr));
		Form1->WrBytes = iBytesWrite;
		Form1->ProgressBar3->Position = i;
		Form1->Label8->Caption = i;
	}
	//ShowMessage(iBytesRead);
	//ShowMessage(iBytesWrite);


	FileClose(iNewFileHandle);
	ShowMessage("������");

//    for(int i = 0; i<1000000; i++){}
//	exit(0);
	Form1->in.clear();
	Form1->strHeaderVec.clear();
	Terminate();
	Form1->Label6->Caption = "";
	Form1->Label7->Caption = "";
	Form1->Label8->Caption = "";
    Form1->Label11->Caption = "";

}
//---------------------------------------------------------------------------
