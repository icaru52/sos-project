// File: frame.h
// Project: SOS Semester Project
// Programmer: Ian Rowse

#ifndef SOS_INCLUDE_FRAME_H_
#define SOS_INCLUDE_FRAME_H_

// This will only take effect if the compiler supports precompilation.
#include <wx/wxprec.h>

// This will take effect if the compiler does not support precompilation.
#ifndef WX_PRECOMP
  #include <wx/wx.h>
#endif // WX_PRECOMP

#include "board.h"

class Frame: public wxFrame
{
 public:
  Frame(const wxString& title, const wxPoint& pos, const wxSize& size, 
      const int width,  const int height);
  ~Frame();
  void onButtonClicked(wxCommandEvent& evt);

 private:
  Board board_;
  wxButton** btns_;

  wxRadioButton* rb_simple_;
  wxRadioButton* rb_general_;
  wxRadioButton* rb_s_;
  wxRadioButton* rb_o_;

  wxDECLARE_EVENT_TABLE();
};

#endif // SOS_INCLUDE_FRAME_H_

