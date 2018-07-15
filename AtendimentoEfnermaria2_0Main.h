/***************************************************************
 * Name:      AtendimentoEfnermaria2_0Main.h
 * Purpose:   Defines Application Frame
 * Author:    Ciro ()
 * Created:   2018-06-19
 * Copyright: Ciro ()
 * License:
 **************************************************************/

#ifndef ATENDIMENTOEFNERMARIA2_0MAIN_H
#define ATENDIMENTOEFNERMARIA2_0MAIN_H

//(*Headers(AtendimentoEfnermaria2_0Frame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/datectrl.h>
#include <wx/panel.h>
#include <wx/dateevt.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/combobox.h>
#include <wx/statusbr.h>
//*)

class AtendimentoEfnermaria2_0Frame: public wxFrame
{
    public:

        AtendimentoEfnermaria2_0Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~AtendimentoEfnermaria2_0Frame();

    private:

        //(*Handlers(AtendimentoEfnermaria2_0Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnChoice1Select(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(AtendimentoEfnermaria2_0Frame)
        static const long ID_CHOICE1;
        static const long ID_CHOICE2;
        static const long ID_DATEPICKERCTRL1;
        static const long ID_COMBOBOX1;
        static const long ID_COMBOBOX2;
        static const long ID_COMBOBOX3;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_COMBOBOX4;
        static const long ID_STATICTEXT7;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT10;
        static const long ID_STATICTEXT11;
        static const long ID_STATICTEXT12;
        static const long ID_STATICTEXT13;
        static const long ID_TEXTCTRL6;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_PANEL1;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(AtendimentoEfnermaria2_0Frame)
        wxStaticText* StaticText10;
        wxStaticText* StaticText9;
        wxTextCtrl* TextCtrl4;
        wxDatePickerCtrl* DatePickerCtrl1;
        wxStaticText* StaticText13;
        wxStaticText* StaticText2;
        wxButton* Button1;
        wxStaticText* StaticText6;
        wxTextCtrl* TextCtrl6;
        wxStaticText* StaticText8;
        wxStaticText* StaticText11;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxButton* Button2;
        wxComboBox* ComboBox4;
        wxComboBox* ComboBox3;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl2;
        wxComboBox* ComboBox1;
        wxTextCtrl* TextCtrl1;
        wxStaticText* StaticText12;
        wxComboBox* ComboBox2;
        wxTextCtrl* TextCtrl5;
        wxStaticText* StaticText4;
        wxTextCtrl* TextCtrl3;
        wxChoice* Choice1;
        wxChoice* Choice2;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ATENDIMENTOEFNERMARIA2_0MAIN_H
