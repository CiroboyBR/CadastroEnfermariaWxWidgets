/***************************************************************
 * Name:      AtendimentoEfnermaria2_0Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Ciro ()
 * Created:   2018-06-19
 * Copyright: Ciro ()
 * License:
 **************************************************************/

#include "AtendimentoEfnermaria2_0Main.h"
#include <clocale>
#include <stdexcept>
#include <wx/textfile.h>
#include <wx/html/htmprint.h>
#include <wx/msgdlg.h>
#include <wx/aboutdlg.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//(*InternalHeaders(AtendimentoEfnermaria2_0Frame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)


//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}
//Protótipos de funções criadas
void InsereNoCombobox(wxComboBox *cbox);
void EscreveArquivo(fstream *Arquivo, string Campo, wxString Valor);
void EscreveArquivoTexto(fstream *Arquivo, string Campo, wxString Valor);

//Variaveis criadas
bool iniciou = false;


//(*IdInit(AtendimentoEfnermaria2_0Frame)
const long AtendimentoEfnermaria2_0Frame::ID_CHOICE1 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_CHOICE2 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_DATEPICKERCTRL1 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_COMBOBOX1 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_COMBOBOX2 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_COMBOBOX3 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_STATICTEXT1 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_STATICTEXT2 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_STATICTEXT3 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_STATICTEXT4 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_STATICTEXT5 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_STATICTEXT6 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_COMBOBOX4 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_STATICTEXT7 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_TEXTCTRL1 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_TEXTCTRL2 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_TEXTCTRL3 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_TEXTCTRL4 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_TEXTCTRL5 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_STATICTEXT8 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_STATICTEXT9 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_STATICTEXT10 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_STATICTEXT11 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_STATICTEXT12 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_STATICTEXT13 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_TEXTCTRL6 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_BUTTON1 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_BUTTON2 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_PANEL1 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_MENUITEM1 = wxNewId();
const long AtendimentoEfnermaria2_0Frame::idMenuAbout = wxNewId();
const long AtendimentoEfnermaria2_0Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(AtendimentoEfnermaria2_0Frame,wxFrame)
    //(*EventTable(AtendimentoEfnermaria2_0Frame)
    //*)
END_EVENT_TABLE()

AtendimentoEfnermaria2_0Frame::AtendimentoEfnermaria2_0Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(AtendimentoEfnermaria2_0Frame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("REGISTROS DE ATENDIMENTOS - ENFERMARIA"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(800,600));
    wxFont thisFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Times New Roman"),wxFONTENCODING_DEFAULT);
    SetFont(thisFont);
    SetHelpText(_("Programa de registro de atendimentos da ENFERMARIA - Modo offline"));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("cruz.ico"))));
    	SetIcon(FrameIcon);
    }
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(256,152), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetHelpText(_("Programa de registro de atendimentos da ENFERMARIA - Modo offline"));
    Choice1 = new wxChoice(Panel1, ID_CHOICE1, wxPoint(176,24), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->SetSelection( Choice1->Append(_("ENFERMEIRO 1")) );
    Choice1->Append(_("ENFERMEIRA 2"));
    Choice1->Append(_("MEDICO 1"));
    Choice1->Append(_("TECNICO DE ENFERMAGEM 1"));
    Choice1->Append(_("DIGITADOR"));
    Choice2 = new wxChoice(Panel1, ID_CHOICE2, wxPoint(176,64), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    Choice2->SetSelection( Choice2->Append(_("ENFERMEIRO 1")) );
    Choice2->Append(_("ENFERMEIRA 2"));
    Choice2->Append(_("MEDICO 1"));
    Choice2->Append(_("TECNICO DE ENFERMAGEM 1"));
    DatePickerCtrl1 = new wxDatePickerCtrl(Panel1, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxPoint(176,112), wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
    ComboBox1 = new wxComboBox(Panel1, ID_COMBOBOX1, wxEmptyString, wxPoint(176,168), wxDefaultSize, 0, 0, wxCB_SORT, wxDefaultValidator, _T("ID_COMBOBOX1"));
    ComboBox1->SetSelection( ComboBox1->Append(_("NAO")) );
    ComboBox2 = new wxComboBox(Panel1, ID_COMBOBOX2, wxEmptyString, wxPoint(176,200), wxDefaultSize, 0, 0, wxCB_SORT, wxDefaultValidator, _T("ID_COMBOBOX2"));
    ComboBox2->SetSelection( ComboBox2->Append(_("NAO")) );
    ComboBox3 = new wxComboBox(Panel1, ID_COMBOBOX3, wxEmptyString, wxPoint(176,232), wxDefaultSize, 0, 0, wxCB_SORT, wxDefaultValidator, _T("ID_COMBOBOX3"));
    ComboBox3->SetSelection( ComboBox3->Append(_("NAO")) );
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("CADASTRADO POR:"), wxPoint(16,28), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("ATENDIDO POR: "), wxPoint(16,68), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("DATA DO ATEND : "), wxPoint(16,116), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("VACINA:"), wxPoint(16,170), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("PATOLOGIA:"), wxPoint(16,204), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("MEDICAMENTO: "), wxPoint(16,236), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    ComboBox4 = new wxComboBox(Panel1, ID_COMBOBOX4, wxEmptyString, wxPoint(112,312), wxSize(400,27), 0, 0, wxCB_SORT, wxDefaultValidator, _T("ID_COMBOBOX4"));
    ComboBox4->SetSelection( ComboBox4->Append(_("PACIENTE 0")) );
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("PACIENTE:"), wxPoint(16,316), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("60"), wxPoint(656,24), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("1,60"), wxPoint(656,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, _("120/80"), wxPoint(656,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl4 = new wxTextCtrl(Panel1, ID_TEXTCTRL4, _("0"), wxPoint(656,144), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    TextCtrl5 = new wxTextCtrl(Panel1, ID_TEXTCTRL5, _("36,6"), wxPoint(656,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("PESO (Kg) : "), wxPoint(512,30), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT9, _("ALTURA (m) : "), wxPoint(512,70), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT10, _("PRESSÃO ART:"), wxPoint(512,110), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    StaticText11 = new wxStaticText(Panel1, ID_STATICTEXT11, _("GLICEMIA:"), wxPoint(512,150), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    StaticText12 = new wxStaticText(Panel1, ID_STATICTEXT12, _("TEMPERATURA ºC :"), wxPoint(512,190), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    StaticText13 = new wxStaticText(Panel1, ID_STATICTEXT13, _("ATENDIMENTO"), wxPoint(288,368), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    wxFont StaticText13Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText13->SetFont(StaticText13Font);
    TextCtrl6 = new wxTextCtrl(Panel1, ID_TEXTCTRL6, _("DIGITAR AQUI O ATENDIMENTO"), wxPoint(24,400), wxSize(760,192), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("CADASTRAR ATENDIMENTO"), wxPoint(552,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("LIMPAR DADOS"), wxPoint(552,312), wxSize(232,29), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Sair\tAlt-F4"), _("Sair do programa"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("Arquivo"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("Sobre\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Ajuda"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AtendimentoEfnermaria2_0Frame::OnButton1Click);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AtendimentoEfnermaria2_0Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AtendimentoEfnermaria2_0Frame::OnAbout);
    //*)
}

AtendimentoEfnermaria2_0Frame::~AtendimentoEfnermaria2_0Frame()
{
    //(*Destroy(AtendimentoEfnermaria2_0Frame)
    //*)
}

void AtendimentoEfnermaria2_0Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void AtendimentoEfnermaria2_0Frame::OnAbout(wxCommandEvent& event)
{
    wxAboutDialogInfo info;
    info.SetName(_("Atendimento Enfermaria"));
    info.SetVersion(_(" v1.0.0 Beta"));
    info.SetDescription(_("Programa para cadastro de atendimentos da enfermaria."));
    info.SetCopyright(_T("(GPL 3.0) - 2018 - Ciro Meneses - www.github.com/CiroboyBR"));

    wxAboutBox(info);
}


//Botão cadastra atendimento
void AtendimentoEfnermaria2_0Frame::OnButton1Click(wxCommandEvent& event)
{
    //inicia linguagem
    if (iniciou == false)
    {
        std::locale loc;     // initialized to locale::classic()

        setlocale(LC_ALL, "Portuguese");

        try
        {
            loc = std::locale ("PT.UTF8");
        }
        catch (std::runtime_error)
        {
            loc = std::locale (loc, "", std::locale::ctype);
        }
        iniciou = true;
    }
    //termina linguagem


    InsereNoCombobox(ComboBox1);
    InsereNoCombobox(ComboBox2);
    InsereNoCombobox(ComboBox3);
    InsereNoCombobox(ComboBox4);

    //Cria arquivo
    fstream arq, arq_texto;
    arq.open("atendimentos.xml", ios::out | ios::app);
    arq_texto.open("atendimentos_texto.txt", ios::out | ios::app);
    //inicio do atendimento no arquivo XML
    arq << "<atendimento>";
    arq << "\n";

    //Escreve no arquivo XML
    EscreveArquivo(&arq, "CADASTRADOR", Choice1->GetString(Choice1->GetSelection()));
    EscreveArquivo(&arq, "ATENDENTE", Choice2->GetString(Choice2->GetSelection()));
    EscreveArquivo(&arq, "DATA", DatePickerCtrl1->GetValue().Format("%d/%m/%Y"));
    EscreveArquivo(&arq, "VACINA", ComboBox1->GetValue());
    EscreveArquivo(&arq, "PATOLOGIA", ComboBox2->GetValue());
    EscreveArquivo(&arq, "MEDICAMENTO", ComboBox3->GetValue());
    EscreveArquivo(&arq, "PACIENTE", ComboBox4->GetValue());
    EscreveArquivo(&arq, "PESO", TextCtrl1->GetValue());
    EscreveArquivo(&arq, "ALTURA", TextCtrl2->GetValue());
    EscreveArquivo(&arq, "PRESSAO", TextCtrl3->GetValue());
    EscreveArquivo(&arq, "GLICEMIA", TextCtrl4->GetValue());
    EscreveArquivo(&arq, "TEMPERATURA", TextCtrl5->GetValue());
    EscreveArquivo(&arq, "RELATO_ATENDIMENTO", TextCtrl6->GetValue());

    //Escreve em arquivo de texto
    EscreveArquivoTexto(&arq_texto, "CADASTRADOR", Choice1->GetString(Choice1->GetSelection()));
    EscreveArquivoTexto(&arq_texto, "ATENDENTE", Choice2->GetString(Choice2->GetSelection()));
    EscreveArquivoTexto(&arq_texto, "DATA", DatePickerCtrl1->GetValue().Format("%d/%m/%Y"));
    EscreveArquivoTexto(&arq_texto, "VACINA", ComboBox1->GetValue());
    EscreveArquivoTexto(&arq_texto, "PATOLOGIA", ComboBox2->GetValue());
    EscreveArquivoTexto(&arq_texto, "MEDICAMENTO", ComboBox3->GetValue());
    EscreveArquivoTexto(&arq_texto, "PACIENTE", ComboBox4->GetValue());
    EscreveArquivoTexto(&arq_texto, "PESO", TextCtrl1->GetValue());
    EscreveArquivoTexto(&arq_texto, "ALTURA", TextCtrl2->GetValue());
    EscreveArquivoTexto(&arq_texto, "PRESSAO", TextCtrl3->GetValue());
    EscreveArquivoTexto(&arq_texto, "GLICEMIA", TextCtrl4->GetValue());
    EscreveArquivoTexto(&arq_texto, "TEMPERATURA", TextCtrl5->GetValue());
    EscreveArquivoTexto(&arq_texto, "RELATO_ATENDIMENTO", TextCtrl6->GetValue());

    //finaliza o atendimento e o arquivo XML
    arq << "</atendimento>";
    arq << "\n\n";
    arq.close();

    //Finaliza o Arquivo de texto
    arq_texto << "\n";
    arq_texto.close();


}

void InsereNoCombobox(wxComboBox *cbox) {
     //para Evitar valores repetidos
    bool copia = true;
    wxString s = cbox->GetValue();


    //para debugs
    cout << "Atual: "<< cbox->GetValue().ToStdString() << endl;

    //Percorre o combobox
    int n = cbox->GetCount();
    for(int i = 0; i < n; i++ ){
        //para debug
        cout << "Item " << i << ": "<< cbox->GetString(i).ToStdString() << endl;

        //Se já existe desativa a inserção da string como um novo valor no combobox
        if(cbox->GetString(i).MakeUpper().ToStdString() == s.MakeUpper().ToStdString())
            copia = false;
    }

    //Se a cópia estiver ativada, insere um novo registro no combobox em letras maísculas
    if (copia)
        cbox->Append(cbox->GetValue().MakeUpper() );

}

//Escreve o CAMPO e o VALOR_DO_CAMPO no arquivo de registro dos atendimentos
void EscreveArquivo(fstream *Arquivo, string Campo, wxString Valor) {
    //Abre TAG com o nome do campo
    *Arquivo << "\t<";
    *Arquivo << Campo;
    *Arquivo << ">";

    //valor do campo dentro da TAG
    *Arquivo << Valor;

    //Fecha a TAG do campo
    *Arquivo << "</";
    *Arquivo << Campo;
    *Arquivo << ">\n";
}

//Escreve o em texto Puro para ser lido
void EscreveArquivoTexto(fstream *Arquivo, string Campo, wxString Valor) {
    //Escreve o campo
    *Arquivo << Campo;
    *Arquivo << ": ";

    //valor do campo dentro
    *Arquivo << Valor;
    *Arquivo << "\n";
}
