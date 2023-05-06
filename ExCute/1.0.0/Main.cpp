#include <wx/wx.h>
#include <fstream>
#pragma warning(disable : 4996)
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
};
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);
}
class App :public wxApp
{
public:
	bool OnInit();
};
wxIMPLEMENT_APP(App);
bool App::OnInit()
{
	std::string VERSION = "1.0.0";
	MainFrame* mainFrame = new MainFrame("ExCute " + VERSION);
	mainFrame->SetClientSize(800, 600);
	mainFrame->Centre();
	mainFrame->Show();
	std::string HFOLDER_roaming = getenv("APPDATA");
	std::string IFOLDER_EX = HFOLDER_roaming + "\\Ex\\";
	std::string IFOLDER_APP = IFOLDER_EX + "ExCute\\";
	std::string IFOLDER_VER = IFOLDER_APP + VERSION + "\\";
	std::string FILE_CONFIG = IFOLDER_VER + "CONFIG.exf";
	std::ifstream CONFIG;
	CONFIG.open(FILE_CONFIG);
	if (!CONFIG)
	{
		std::string cmdIFOLDER_EX = "MD " + HFOLDER_roaming + "\\Ex\\";
		system(cmdIFOLDER_EX.c_str());
		std::string cmdIFOLDER_APP = "MD " + IFOLDER_EX + "ExCute\\";
		system(cmdIFOLDER_APP.c_str());
		std::string cmdIFOLDER_VER = "MD " + IFOLDER_APP + VERSION + "\\";
		system(cmdIFOLDER_VER.c_str());
		std::ofstream config_new(FILE_CONFIG);
		std::string config_new_text = "</ex>\n    </config>\n    <config/>\n<ex/>";
		config_new << config_new_text;
		config_new.close();
	}
	return true;
}