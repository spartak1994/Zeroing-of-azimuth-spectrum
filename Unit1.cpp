//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "MyThread.h"
#include <cstdlib>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	OpenDialog1->Execute();
	Edit1->Text = OpenDialog1->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	SaveDialog1->Execute();
	Edit2->Text = SaveDialog1->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Button3->Enabled = false;
	//isUpdateForm = true;
	MyThread *thread = new MyThread(false);
	//Form3->ProgressBar1->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
	SaveDialog2->Execute();
	int iNewFileHandle = FileCreate(SaveDialog2->FileName);
	FileClose(iNewFileHandle);
	iNewFileHandle = FileOpen(SaveDialog2->FileName, fmOpenWrite);
	UnicodeString inputFile = Edit1->Text;
	UnicodeString outputFile = Edit2->Text;
	UnicodeString start = Edit3->Text;
	UnicodeString end = Edit4->Text;
	UnicodeString endl = "\n";
	UnicodeString BPF = (UnicodeString)ComboBox1->ItemIndex;
	FileWrite(iNewFileHandle,((AnsiString)inputFile).c_str(), inputFile.Length());
	FileWrite(iNewFileHandle,((AnsiString)endl).c_str(), endl.Length());
	FileWrite(iNewFileHandle,((AnsiString)outputFile).c_str(), outputFile.Length());
	FileWrite(iNewFileHandle,((AnsiString)endl).c_str(), endl.Length());
	FileWrite(iNewFileHandle,((AnsiString)start).c_str(), start.Length());
	FileWrite(iNewFileHandle,((AnsiString)endl).c_str(), endl.Length());
	FileWrite(iNewFileHandle,((AnsiString)end).c_str(), end.Length());
	FileWrite(iNewFileHandle,((AnsiString)endl).c_str(), endl.Length());
	FileWrite(iNewFileHandle,((AnsiString)BPF).c_str(), BPF.Length());
	FileWrite(iNewFileHandle,((AnsiString)endl).c_str(), endl.Length());


	FileClose(iNewFileHandle);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
	OpenDialog2->Execute();
	Memo1->Lines->LoadFromFile(OpenDialog2->FileName);
	UnicodeString inputFile = (UnicodeString)Memo1->Lines->Strings[0];
	UnicodeString outputFile = (UnicodeString)Memo1->Lines->Strings[1];
	UnicodeString start = (UnicodeString)Memo1->Lines->Strings[2];
	UnicodeString end = (UnicodeString)Memo1->Lines->Strings[3];
	int BPF = StrToInt(Memo1->Lines->Strings[4]);
	//ShowMessage(inputFile);
	Edit1->Text = inputFile;
	Edit2->Text = outputFile;
	Edit3->Text = start;
	Edit4->Text = end;
	ComboBox1->ItemIndex = BPF;


}
//---------------------------------------------------------------------------

