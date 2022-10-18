// File: frame.cc
// Project: SOS Semester Project
// Programmer: Ian Rowse

#include "frame.h"

wxBEGIN_EVENT_TABLE(Frame, wxFrame) wxEND_EVENT_TABLE();

Frame::Frame(const wxString& title, const wxPoint& pos, const wxSize& size, 
    const int width, const int height)
      : wxFrame(NULL, wxID_ANY, title, pos, size),
        board_(width, height)
{
  wxBoxSizer *hbox0 = new wxBoxSizer(wxHORIZONTAL);

  btns_ = new wxButton * [width * height];
  wxGridSizer* grid = new wxGridSizer(height, width, 5, 5);
  wxFont font(36, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

  for(int i = 0; i < width * height; ++i)
  {
    btns_[i] = new wxButton(this, 10000 + i);
    grid->Add(btns_[i], 1, wxEXPAND | wxALL);
    btns_[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Frame::onButtonClicked, this);
    btns_[i]->SetFont(font);
    btns_[i]->SetBackgroundColour(wxColour(*wxBLACK));
  }
  this->SetSizer(grid);
  grid->Layout();

  wxPanel *panel = new wxPanel(this, -1);

  wxButton *btn0 = new wxButton(panel, wxID_ANY, wxT("Hello"));

  hbox0->Add(grid, 0, wxLEFT, 8);
  hbox0->Add(btn0, 0);
  //hbox0->Add(panel, 0, wxEXPAND, 10);
}

Frame::~Frame()
{
  delete[] btns_; 
}

void Frame::onButtonClicked(wxCommandEvent& evt)
{
  int rows = board_.GetHeight();
  int i = evt.GetId() - 10000;
  int y = i % rows;
  int x = i / rows;

  Cell* cell = &board_.GetCell(y, x);

  cell->SetS();

  btns_[i]->SetLabel(cell->GetSymbol());

  //board_.CountFilledCells();
}

