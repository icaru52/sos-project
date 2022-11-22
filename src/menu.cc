// File: menu.cc
// Project: SOS Semester Project
// Programmer: Ian Rowse

#include "menu.h"

wxBEGIN_EVENT_TABLE(Menu, wxFrame) wxEND_EVENT_TABLE();

Menu::Menu(const wxString& title, const wxPoint& pos, const wxSize& size)
      : wxFrame(NULL, wxID_ANY, title, pos, size)
{
  wxBoxSizer* box = new wxBoxSizer(wxVERTICAL);

  text_ = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, 
      wxDefaultSize, wxTE_PROCESS_ENTER);
  box->Add(text_);
 
  btn_ = new wxButton(this, wxID_ANY);
  box->Add(btn_);

  this->SetSizer(box);
  box->Layout();

  //text_->Bind(wxEVT_TEXT_ENTER, &Menu::onTextBoxEnter, this);

  btn_->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Menu::onButtonClicked, this);
}

/*
Menu::~Menu()
{
  text_->Destroy();
}
*/

void Menu::onButtonClicked(wxCommandEvent& evt)
{
  int dimension = wxAtoi(text_->GetLineText(0));
  //ResizeGrid(dimension, dimension);
}

/*
void Menu::onTextBoxEnter(wxCommandEvent& event)
{
  int dimension = wxAtoi(text_->GetLineText(0));
  ResizeGrid(dimension, dimension);
}
*/

