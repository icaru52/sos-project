// File: menu.h
// Project: SOS Semester Project
// Programmer: Ian Rowse

#ifndef SOS_INCLUDE_MENU_H_
#define SOS_INCLUDE_MENU_H_

// This will only take effect if the compiler supports precompilation.
#include <wx/wxprec.h>

// This will take effect if the compiler does not support precompilation.
#ifndef WX_PRECOMP
  #include <wx/wx.h>
#endif // WX_PRECOMP

class Menu: public wxFrame
{
 public:
  Menu(const wxString& title, const wxPoint& pos, const wxSize& size);
  //~Menu();
  void onButtonClicked(wxCommandEvent& event);
  //void onTextBoxEnter(wxCommandEvent& event);

 private:
  wxTextCtrl* text_;
  wxButton* btn_;

  wxDECLARE_EVENT_TABLE();
};

#endif // SOS_INCLUDE_MENU_H_

