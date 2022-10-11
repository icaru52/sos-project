// File: app.cc
// Project: SOS Semester Project
// Programmer: Ian Rowse

#include "app.h"

IMPLEMENT_APP(App);

bool App::OnInit()
{
  frame_ = new Frame("SOS", wxPoint(64, 64), wxSize(512, 512), 5, 5);
  frame_->Show();
  return true;
}

