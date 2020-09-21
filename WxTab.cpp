#include "WxTab.h"

WxTab::WxTab(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxPanel(parent, id, pos, size, style, name)
{
	wxBoxSizer* MainPanel;
	MainPanel = new wxBoxSizer(wxVERTICAL);

	CmbAddress = new wxComboBox(this, wxID_ANY, wxT("https://google.com"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	MainPanel->Add(CmbAddress, 0, wxALL | wxEXPAND, 5);

	WebView = new wxHtmlWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO);
	MainPanel->Add(WebView, 1, wxALL | wxEXPAND, 5);


	this->SetSizer(MainPanel);
	this->Layout();

	// Connect Events
	CmbAddress->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(WxTab::Address_Select), NULL, this);
	CmbAddress->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(WxTab::Address_Change), NULL, this);
	CmbAddress->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(WxTab::Address_Enter), NULL, this);
}

void WxTab::Address_Select(wxCommandEvent& event) 
{
	OpenUrl();
}

void WxTab::Address_Change(wxCommandEvent& event) 
{
	//OpenUrl();
}

void WxTab::Address_Enter(wxCommandEvent& event) 
{
	OpenUrl();
}

void WxTab::OpenUrl()
{
	WebView->LoadPage(CmbAddress->GetValue());
}

WxTab::~WxTab()
{
	// Disconnect Events
	CmbAddress->Disconnect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(WxTab::Address_Select), NULL, this);
	CmbAddress->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(WxTab::Address_Change), NULL, this);
	CmbAddress->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(WxTab::Address_Enter), NULL, this);

}