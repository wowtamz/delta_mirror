#include <random>
#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/dir.h>
#include <wx/filename.h>

class MyFrame : public wxFrame
{
    public:
        MyFrame();
        wxListCtrl* list;

    private:
        void OnButtonClicked(wxCommandEvent& event);

        wxButton* m_button;
};

class MyApp : public wxApp
{
    public:
        bool OnInit() override;
};

MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Button Example", wxDefaultPosition, wxSize(1280, 720))
{
    auto* panel = new wxPanel(this);
    
    list = new wxListCtrl(
            panel,
            wxID_ANY,
            wxDefaultPosition,
            wxDefaultSize,
            wxLC_REPORT | wxLC_SINGLE_SEL
    );

    list->AppendColumn("Name", wxLIST_FORMAT_LEFT, 250);
    list->AppendColumn("Size", wxLIST_FORMAT_RIGHT, 100);

    m_button = new wxButton(panel, wxID_ANY, "Click Me");

    auto* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(m_button, 0, wxALL | wxCENTER, 60);

    panel->SetSizer(sizer);

    m_button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClicked, this);
}

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> rand_range(10, 250);

    auto* frame = new MyFrame();

    for (int i = 0; i < 5; i++) {

        wxString item_name = wxString::Format("Item %d", i);
        int item_count = frame->list->GetItemCount();
        long row = frame->list->InsertItem(item_count, item_name);
        
        int rand_size = rand_range(gen);
        wxString file_size = wxString::Format("%d MB", rand_size);

        frame->list->SetItem(row, 1, file_size);
    }

    frame->Show();
    return true;
}

void MyFrame::OnButtonClicked(wxCommandEvent& event)
{
    wxMessageBox(
            "You clicked the button!",
            "Hello",
            wxOK | wxICON_INFORMATION,
            this
    );
}
