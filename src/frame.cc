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
  wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

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
  grid->Layout();

  hbox->Add(grid, 0, wxLEFT | wxEXPAND, 10);

  wxTextCtrl *text = new wxTextCtrl(this, wxID_ANY);
  vbox->Add(text);

  rb_simple_ = new wxRadioButton(this, wxID_ANY, wxT("Simple Game"), 
      wxDefaultPosition, wxDefaultSize, wxRB_GROUP);
  vbox->Add(rb_simple_);
  rb_general_ = new wxRadioButton(this, wxID_ANY, wxT("General Game"));
  vbox->Add(rb_general_);
  
  rb_s_ = new wxRadioButton(this, wxID_ANY, wxT("S"), wxDefaultPosition, 
      wxDefaultSize, wxRB_GROUP);
  vbox->Add(rb_s_);
  rb_o_ = new wxRadioButton(this, wxID_ANY, wxT("O"));
  vbox->Add(rb_o_);

  hbox->Add(vbox, 0, wxRIGHT | wxEXPAND, 10);

  this->SetSizer(hbox);
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

  char letter = rb_s_->GetValue() ? 'S' : 'O';

  board_.SetMark(y, x, letter);

  btns_[i]->SetLabel(board_.GetMark(y, x));
}

