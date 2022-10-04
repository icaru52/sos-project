// File: cell.cc
// Project: SOS Semester Project
// Programmer: Ian Rowse

#include "cell.h"

Cell::Cell()
{
  symbol_ = ' ';
}

char Cell::GetSymbol() const { return symbol_; }

void Cell::SetSymbol(const char symbol)
{
  switch(symbol)
  {
    case ' ':
    case 'S':
    case 'O':
      this->symbol_ = symbol;
      break;
    default:
      break;
  }
}

bool Cell::IsEmpty() const { return symbol_ == ' '; }
void Cell::SetEmpty() { symbol_ = ' '; }

bool Cell::IsS() const { return symbol_ == 'S'; }
void Cell::SetS() { symbol_ = 'S'; }

bool Cell::IsO() const { return symbol_ == 'O'; }
void Cell::SetO() { symbol_ = 'O'; }


