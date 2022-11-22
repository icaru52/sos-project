// File: grid.cc
// Project: SOS Semester Project
// Programmer: Ian Rowse

#include "grid.h"
//#include <iostream>

wxBEGIN_EVENT_TABLE(Grid, wxWindow) wxEND_EVENT_TABLE();

Grid::Grid(wxWindow* parent, wxWindowID id, const int width, const int height)
  : wxWindow(parent, id),
    board_(height, width)
{
  btns_ = new wxButton * [width * height];
  grid_ = new wxGridSizer(width, height, 5, 5);
  wxFont font(36, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

  //std::cout << "grid.cc test" << std::endl;

  for(int i = 0; i < width * height; ++i)
  {
    btns_[i] = new wxButton(parent, 10000 + i);
    grid_->Add(btns_[i], 1, wxEXPAND | wxALL);
    btns_[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Grid::onButtonClicked, this);
    btns_[i]->SetFont(font);
    btns_[i]->SetBackgroundColour(wxColour(*wxBLACK));
    //btns_[i]->Show();
  }
  //mistake, only apply to tables
  //grid_->SetDefaultColSize(50);
  //grid_->SetDefaultRowSize(50);
  grid_->Layout();
  this->SetBackgroundColour(wxColour(*wxWHITE));
  this->SetMinSize(wxSize(100, 100));
  //this->SetMaxSize(wxSize(150, 150));
  this->Show();
}

Grid::~Grid()
{
  for(int i = 0; i < board_.GetWidth() * board_.GetHeight(); ++i)
  {
    btns_[i]->Destroy();
  }
  delete[] btns_;
  delete grid_;
  //delete board_;
}

void Grid::onButtonClicked(wxCommandEvent& evt)
{
  int rows = board_.GetHeight();
  int i = evt.GetId() - 10000;
  int y = i % rows;
  int x = i / rows;

  //char letter = rb_s_->GetValue() ? 'S' : 'O';

  //board_.SetMark(y, x, letter);

  btns_[i]->SetLabel(board_.GetMark(y, x));
}

