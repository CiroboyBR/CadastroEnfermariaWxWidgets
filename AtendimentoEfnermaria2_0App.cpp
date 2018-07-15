/***************************************************************
 * Name:      AtendimentoEfnermaria2_0App.cpp
 * Purpose:   Code for Application Class
 * Author:    Ciro ()
 * Created:   2018-06-19
 * Copyright: Ciro ()
 * License:
 **************************************************************/

#include "AtendimentoEfnermaria2_0App.h"

//(*AppHeaders
#include "AtendimentoEfnermaria2_0Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(AtendimentoEfnermaria2_0App);

bool AtendimentoEfnermaria2_0App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	AtendimentoEfnermaria2_0Frame* Frame = new AtendimentoEfnermaria2_0Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
