#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/aui/auibook.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

class Sample : public wxFrame
{
private:

protected:
	wxAuiNotebook* TabbedView;
	wxMenuBar* MenubarMain;
	wxMenu* MenuFile;
	wxMenu* MenuPreferences;
	wxMenu* MenuHelp;
	wxStatusBar* StatusBarMain;

public:

	Sample(const wxString& title);
	~Sample();

};