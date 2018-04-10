//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include "rgg.h"
#include  "ipps.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <vector>


struct Complex
{
	float Re;
	float Im;
};

struct KStr
{
	//Complex mas[32768];
	Complex mas[16384];
};

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TEdit *Edit3;
	TEdit *Edit4;
	TLabel *Label1;
	TLabel *Label2;
	TProgressBar *ProgressBar1;
	TProgressBar *ProgressBar2;
	TProgressBar *ProgressBar3;
	TTimer *Timer1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TComboBox *ComboBox1;
	TLabel *Label9;
	TButton *Button4;
	TButton *Button5;
	TLabel *Label10;
	TLabel *Label11;
	TSaveDialog *SaveDialog2;
	TOpenDialog *OpenDialog2;
	TMemo *Memo1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	__int64 allBytes;
	__int64 WrBytes;
	boolean isUpdateForm = false;
	std::vector<KStr> in;
	std::vector<RggStrHeader> strHeaderVec;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
