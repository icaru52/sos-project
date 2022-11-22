// File: app.h
// Project: SOS Semester Project
// Programmer: Ian Rowse

#ifndef SOS_INCLUDE_APP_H_
#define SOS_INCLUDE_APP_H_

// This will only take effect if the compiler supports precompilation.
#include <wx/wxprec.h>

// This will take effect if the compiler does not support precompilation.
#ifndef WX_PRECOMP
  #include <wx/wx.h>
#endif // WX_PRECOMP

#include "menu.h"
#include "frame.h"

class App : public wxApp
{
 public:
  virtual bool OnInit();

 private:
  Menu* menu_ = nullptr;
  Frame* frame_ = nullptr;
};

#endif // SOS_INCLUDE_APP_H_

