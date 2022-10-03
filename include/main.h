// File: main.h
// Project: SOS Semester Project
// Programmer: Ian Rowse

#ifndef SOS_INCLUDE_MAIN_H_
#define SOS_INCLUDE_MAIN_H_

// This will only take effect if the compiler supports precompilation.
#include <wx/wxprec.h>

// This will take effect if the compiler does not support precompilation.
#ifndef WX_PRECOMP
  #include <wx/wx.h>
#endif

#include "frame.h"

class App : public wxApp
{
 public:
  virtual bool OnInit();

 private:
  Frame* frame_ = nullptr;
};

#endif // SOS_INCLUDE_MAIN_H_

