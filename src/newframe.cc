// File: newframe.cc
// Project: SOS Semester Project
// Programmer: Ian Rowse

#include "newframe.h"
#include <iostream>

wxBEGIN_EVENT_TABLE(Frame, wxFrame) wxEND_EVENT_TABLE();

Frame::Frame(const wxString& title, const wxPoint& pos, const wxSize& size, 
    const int width, const int height)
  : wxFrame(NULL, wxID_ANY, title, pos, size)
{
  hbox_ = new wxBoxSizer(wxHORIZONTAL);
  vbox_ = new wxBoxSizer(wxVERTICAL);

  //grid_ = new Grid(this, wxID_ANY, width, height);
  
  /*
  std::cout << "Grid is " << (grid_->IsShown() ? "" : "not ") << "shown" << std::endl;
  std::cout << "Grid is " << (grid_->IsShownOnScreen() ? "" : "not ") << "shown on screen" << std::endl;
  std::cout << "Show() did " << (grid_->Show() ? "something" : "nothing") << std::endl;
  std::cout << "Grid is " << (grid_->IsShown() ? "" : "not ") << "shown" << std::endl;
  std::cout << "Grid is " << (grid_->IsShownOnScreen() ? "" : "not ") << "shown on screen" << std::endl;
  */

  //hbox_->Add(grid_, 0, wx_ALIGN_LEFT | wxEXPAND, 10);

  text_ = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, 
      wxDefaultSize, wxTE_PROCESS_ENTER);
  
  vbox_->Add(text_);
  text_->Bind(wxEVT_TEXT_ENTER, &Frame::onTextBoxEnter, this);

  rb_simple_ = new wxRadioButton(this, wxID_ANY, wxT("Simple Game"), 
      wxDefaultPosition, wxDefaultSize, wxRB_GROUP);
  vbox_->Add(rb_simple_);
  rb_general_ = new wxRadioButton(this, wxID_ANY, wxT("General Game"));
  vbox_->Add(rb_general_);
  
  rb_s_ = new wxRadioButton(this, wxID_ANY, wxT("S"), wxDefaultPosition, 
      wxDefaultSize, wxRB_GROUP);
  vbox_->Add(rb_s_);
  rb_o_ = new wxRadioButton(this, wxID_ANY, wxT("O"));
  vbox_->Add(rb_o_);

  hbox_->Add(vbox_, 0, /*wxALIGN_RIGHT |*/ wxEXPAND, 10);

  this->SetSizer(hbox_);

  vbox_->Layout();
  hbox_->Layout();

  this->Show();
}

/*
Frame::~Frame()
{
  grid_->Destroy();
  text_->Destroy();

  rb_simple_->Destroy();
  rb_general_->Destroy();
  rb_s_->Destroy();
  rb_o_->Destroy();
}
*/

void Frame::onTextBoxEnter(wxCommandEvent& event)
{
  std::cout << "text box entered" <<std::endl ;
  int dimension = wxAtoi(text_->GetLineText(0));
  grid_ = new Grid(this, wxID_ANY, dimension, dimension);
  hbox_->Add(grid_, 0, /*wxALIGN_LEFT |*/ wxEXPAND, 10);
}

