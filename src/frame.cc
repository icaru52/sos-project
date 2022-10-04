// File: frame.cc
// Project: SOS Semester Project
// Programmer: Ian Rowse

#include "frame.h"

Frame::Frame(const wxString& title, const wxPoint& pos, const wxSize& size, 
    const int width, const int height)
      : wxFrame(NULL, wxID_ANY, title, pos, size),
        board_(width, height)
{
  //board_ = Board(width, height);
  wxGridSizer* grid = new wxGridSizer(height, width, 0, 0);
  wxFont font(36, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

  for(int y = 0; y < height; ++y)
  {
    btns_[y] = new wxButton[width];

    for(int x = 0; x < width; ++x)
    {
      btns_[y][x] = new wxButton(this, 10000 + y*width + x);
      grid->Add(btns_[y][x], 1, wxEXPAND | wxALL);
      btns_[y][x].Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Frame::onButtonClicked, this);
      btns_[y][x].SetFont(font);
      btns_[y][x].SetBackgroundColour(wxColour(*wxBLACK));
    }
  }
  this->SetSizer(grid);
  grid->Layout();
}

Frame::~Frame()
{
  for (int y = 0; y < board_.GetHeight(); ++y)
  {
    delete[] btns_[y];
  }
  delete[] btns_; 
}

void Frame::onButtonClicked(wxCommandEvent& evt)
{
  int rows = board_.GetHeight();
  int y = (evt.GetId() - 10000) % rows;
  int x = (evt.GetId() - 10000) / rows;

}

