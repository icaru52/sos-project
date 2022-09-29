// File: board.h
// Project: SOS Semester Project
// Programmer: Ian Rowse

#ifndef SOSPROJECT_INCLUDE_BOARD_H_
#define SOSPROJECT_INCLUDE_BOARD_H_

#include "cell.h"

class Board
{
 private:
  const int width_;
  const int height_;
  Cell** board_;

 public:
  Board(int width, int height);
  ~Board();
  int  GetWidth() const;
  int  GetHeight() const;
  char GetCell(int row, int col) const;
  void SetCell(int row, int col, char symbol);
  bool IsFull() const;
  bool IsEmpty() const;
  void Clear();
  
};

#endif // SOSPROJECT_INCLUDE_BOARD_H_

