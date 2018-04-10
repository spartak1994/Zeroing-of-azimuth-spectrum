object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1054#1073#1085#1091#1083#1077#1085#1080#1077' '#1072#1079#1091#1084#1091#1090#1072#1083#1100#1085#1086#1075#1086' '#1089#1087#1077#1082#1090#1088#1072
  ClientHeight = 328
  ClientWidth = 422
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 32
    Top = 102
    Width = 58
    Height = 13
    Caption = #1054#1073#1085#1091#1083#1103#1090#1100' '#1089
  end
  object Label2: TLabel
    Left = 166
    Top = 102
    Width = 12
    Height = 13
    Caption = #1087#1086
  end
  object Label3: TLabel
    Left = 32
    Top = 173
    Width = 37
    Height = 13
    Caption = #1063#1090#1077#1085#1080#1077
  end
  object Label4: TLabel
    Left = 32
    Top = 213
    Width = 56
    Height = 13
    Caption = #1054#1073#1088#1072#1073#1086#1090#1082#1072
  end
  object Label5: TLabel
    Left = 32
    Top = 252
    Width = 35
    Height = 13
    Caption = #1047#1072#1087#1080#1089#1100
  end
  object Label6: TLabel
    Left = 296
    Top = 156
    Width = 3
    Height = 13
  end
  object Label7: TLabel
    Left = 296
    Top = 196
    Width = 3
    Height = 13
  end
  object Label8: TLabel
    Left = 296
    Top = 235
    Width = 3
    Height = 13
  end
  object Label9: TLabel
    Left = 32
    Top = 136
    Width = 21
    Height = 13
    Caption = #1041#1055#1060
  end
  object Label10: TLabel
    Left = 32
    Top = 288
    Width = 146
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1089#1090#1088#1086#1082' '#1074' '#1092#1072#1081#1083#1077':  '
  end
  object Label11: TLabel
    Left = 228
    Top = 288
    Width = 3
    Height = 13
  end
  object Edit1: TEdit
    Left = 32
    Top = 24
    Width = 233
    Height = 21
    TabOrder = 0
    TextHint = #1042#1099#1073#1077#1088#1080#1090#1077' '#1074#1093#1086#1076#1085#1086#1081' '#1092#1072#1081#1083
  end
  object Edit2: TEdit
    Left = 32
    Top = 64
    Width = 233
    Height = 21
    TabOrder = 1
    TextHint = #1042#1099#1073#1077#1088#1080#1090#1077' '#1074#1099#1093#1086#1076#1085#1086#1081' '#1092#1072#1081#1083
  end
  object Button1: TButton
    Left = 328
    Top = 22
    Width = 75
    Height = 25
    Caption = '...'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 328
    Top = 62
    Width = 75
    Height = 25
    Caption = '...'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 328
    Top = 247
    Width = 75
    Height = 25
    Caption = #1047#1072#1087#1091#1089#1090#1080#1090#1100
    TabOrder = 4
    OnClick = Button3Click
  end
  object Edit3: TEdit
    Left = 96
    Top = 99
    Width = 48
    Height = 21
    TabOrder = 5
    Text = '0'
  end
  object Edit4: TEdit
    Left = 201
    Top = 99
    Width = 64
    Height = 21
    TabOrder = 6
    Text = '63000'
  end
  object ProgressBar1: TProgressBar
    Left = 96
    Top = 173
    Width = 169
    Height = 17
    Step = 1
    TabOrder = 7
  end
  object ProgressBar2: TProgressBar
    Left = 96
    Top = 213
    Width = 169
    Height = 17
    TabOrder = 8
  end
  object ProgressBar3: TProgressBar
    Left = 96
    Top = 252
    Width = 169
    Height = 17
    TabOrder = 9
  end
  object ComboBox1: TComboBox
    Left = 120
    Top = 133
    Width = 145
    Height = 21
    Style = csDropDownList
    ItemIndex = 0
    TabOrder = 10
    Text = '16384'
    Items.Strings = (
      '16384'
      '32768'
      '65536'
      '131072')
  end
  object Button4: TButton
    Left = 328
    Top = 99
    Width = 75
    Height = 23
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 11
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 328
    Top = 133
    Width = 75
    Height = 25
    Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
    TabOrder = 12
    OnClick = Button5Click
  end
  object Memo1: TMemo
    Left = 624
    Top = 523
    Width = 793
    Height = 182
    Lines.Strings = (
      'Memo1')
    TabOrder = 13
  end
  object OpenDialog1: TOpenDialog
    Left = 504
    Top = 248
  end
  object SaveDialog1: TSaveDialog
    Left = 576
    Top = 216
  end
  object Timer1: TTimer
    Left = 576
    Top = 152
  end
  object SaveDialog2: TSaveDialog
    Left = 576
    Top = 320
  end
  object OpenDialog2: TOpenDialog
    Left = 456
    Top = 344
  end
end
