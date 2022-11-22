// File: grid.h
// Project: SOS Semester Project
// Programmer: Ian Rowse

#ifndef SOS_INCLUDE_GRID_H_
#define SOS_INCLUDE_GRID_H_

// This will only take effect if the compiler supports precompilation.
#include <wx/wxprec.h>

// This will take effect if the compiler does not support precompilation.
#ifndef WX_PRECOMP
  #include <wx/wx.h>
#endif // WX_PRECOMP

#include "board.h"

class Grid: public wxWindow
{
 public:
  Grid(wxWindow* parent, wxWindowID id, const int width, const int height);
  ~Grid();
  void onButtonClicked(wxCommandEvent& event);
  
 private:
  Board board_;
  wxButton** btns_;
  wxGridSizer* grid_;
  
  wxDECLARE_EVENT_TABLE();
};

#endif // SOS_INCLUDE_GRID_H_

