#include "Sample.h"
#include "../WxTab.h"

Sample::Sample(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(350, 200))
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	SetIcon(wxICON(sample));
	wxBoxSizer* LayoutCentral;
	LayoutCentral = new wxBoxSizer(wxVERTICAL);

	TabbedView = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_DEFAULT_STYLE);
	TabbedView->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	TabbedView->SetBackgroundColour(wxColour(255, 255, 255));

	WxTab* tab1 = new WxTab(TabbedView, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_RAISED | wxTAB_TRAVERSAL);
	TabbedView->AddPage(tab1, "New Tab", false, wxNullBitmap);

	LayoutCentral->Add(TabbedView, 1, wxEXPAND | wxALL, 0);

	this->SetSizer(LayoutCentral);
	this->Layout();
	MenubarMain = new wxMenuBar(0);
	MenuFile = new wxMenu();
	wxMenuItem* MenuPrint;
	MenuPrint = new wxMenuItem(MenuFile, wxID_ANY, wxString(wxT("Print")), wxEmptyString, wxITEM_NORMAL);
	MenuFile->Append(MenuPrint);

	MenuFile->AppendSeparator();

	wxMenuItem* MenuExit;
	MenuExit = new wxMenuItem(MenuFile, wxID_ANY, wxString(wxT("Exit")), wxEmptyString, wxITEM_NORMAL);
	MenuFile->Append(MenuExit);

	MenubarMain->Append(MenuFile, wxT("File"));

	MenuPreferences = new wxMenu();
	wxMenuItem* MenuPreferencesSet;
	MenuPreferencesSet = new wxMenuItem(MenuPreferences, wxID_ANY, wxString(wxT("Manage Preferences")), wxEmptyString, wxITEM_NORMAL);
	MenuPreferences->Append(MenuPreferencesSet);

	wxMenuItem* MenuPreferencesReset;
	MenuPreferencesReset = new wxMenuItem(MenuPreferences, wxID_ANY, wxString(wxT("Reset Preferences")), wxEmptyString, wxITEM_NORMAL);
	MenuPreferences->Append(MenuPreferencesReset);

	MenubarMain->Append(MenuPreferences, wxT("Preferences"));

	MenuHelp = new wxMenu();
	wxMenuItem* MenuAbout;
	MenuAbout = new wxMenuItem(MenuHelp, wxID_ANY, wxString(wxT("About this App")), wxEmptyString, wxITEM_NORMAL);
	MenuHelp->Append(MenuAbout);

	wxMenuItem* MenuHow;
	MenuHow = new wxMenuItem(MenuHelp, wxID_ANY, wxString(wxT("How it Works")), wxEmptyString, wxITEM_NORMAL);
	MenuHelp->Append(MenuHow);

	MenubarMain->Append(MenuHelp, wxT("Help"));

	this->SetMenuBar(MenubarMain);

	StatusBarMain = this->CreateStatusBar(1, wxSTB_SIZEGRIP, wxID_ANY);

	this->Centre(wxBOTH);
}

Sample::~Sample()
{
	// Disconnect Events
}
