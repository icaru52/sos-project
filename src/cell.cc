// File: cell.cc
// Project: SOS Semester Project
// Programmer: Ian Rowse

#include "cell.h"

Cell::Cell()
{
  mark_ = ' ';
}

char Cell::GetMark() const { return mark_; }

void Cell::SetMark(const char mark)
{
  switch(mark)
  {
    case ' ':
    case 'S':
    case 'O':
      this->mark_ = mark;
      break;
    default:
      break;
  }
}

bool Cell::MarkIs(const char mark) const
{
  return mark_ == mark;
}

void Cell::SetEmpty() { mark_ = ' '; }
void Cell::SetS() { mark_ = 'S'; }
void Cell::SetO() { mark_ = 'O'; }


