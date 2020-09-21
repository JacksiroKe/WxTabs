#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/combobox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/html/htmlwin.h>
#include <wx/sizer.h>
#include <wx/panel.h>

class WxTab : public wxPanel
{
private:

protected:
	wxComboBox* CmbAddress;
	wxHtmlWindow* WebView;

	void Address_Select(wxCommandEvent& event);
	void Address_Change(wxCommandEvent& event);
	void Address_Enter(wxCommandEvent& event);
	void OpenUrl();

public:
	WxTab(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(639, 300), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString);
	~WxTab();

};