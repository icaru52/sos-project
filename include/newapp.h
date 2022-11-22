// File: newapp.h
// Project: SOS Semester Project
// Programmer: Ian Rowse

#ifndef SOS_INCLUDE_NEWAPP_H_
#define SOS_INCLUDE_NEWAPP_H_

// This will only take effect if the compiler supports precompilation.
#include <wx/wxprec.h>

// This will take effect if the compiler does not support precompilation.
#ifndef WX_PRECOMP
  #include <wx/wx.h>
#endif // WX_PRECOMP

#include "newframe.h"

class App : public wxApp
{
 public:
  virtual bool OnInit();

 private:
  Frame* frame_ = nullptr;
};

#endif // SOS_INCLUDE_NEWAPP_H_

