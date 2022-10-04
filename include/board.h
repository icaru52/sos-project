// File: board.h
// Project: SOS Semester Project
// Programmer: Ian Rowse

#ifndef SOSPROJECT_INCLUDE_BOARD_H_
#define SOSPROJECT_INCLUDE_BOARD_H_

#include "cell.h"

class Board
{
 private:
  int width_;
  int height_;
  Cell** board_;

 public:
  Board(const int width, const int height);
  ~Board();
  int GetWidth() const;
  int GetHeight() const;
  Cell& GetCell(const int row, const int col);
  void SetCell(const int row, const int col, const char symbol);
  bool IsFull() const;
  bool IsEmpty() const;
  void Clear();
};

#endif // SOSPROJECT_INCLUDE_BOARD_H_

