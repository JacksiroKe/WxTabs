#include "wx/app.h"
#include "wx/frame.h"

#include "Sample.h"

// Define a new application
class MainApp : public wxApp
{
public:
	virtual bool OnInit() wxOVERRIDE;

};

wxDECLARE_APP(MainApp);
wxIMPLEMENT_APP(MainApp);

bool MainApp::OnInit()
{
	if (!wxApp::OnInit()) return false;

	Sample* home = new Sample("WxTabs Sample App");
	home->SetSize(900, 600);
	home->Show(true);
	home->Center();
	//home->Maximize(true);

	return true;
}
