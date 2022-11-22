// File: app.cc
// Project: SOS Semester Project
// Programmer: Ian Rowse

#include "app.h"

IMPLEMENT_APP(App);

bool App::OnInit()
{
  menu_ = new Menu("Menu", wxPoint(100,100), wxSize(100, 100));
  frame_ = new Frame("SOS", wxPoint(64, 64), wxSize(512, 512), 5, 5);
  menu_->Show();
  frame_->Show();
  return true;
}

