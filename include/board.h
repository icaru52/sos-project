// File: board.h
// Project: SOS Semester Project
// Programmer: Ian Rowse

#ifndef SOS_INCLUDE_BOARD_H_
#define SOS_INCLUDE_BOARD_H_

#include "cell.h"

class Board
{
 private:
  int width_;
  int height_;
  Cell** grid_;

 public:
  Board(const int width, const int height);
  ~Board();
  int GetWidth() const;
  int GetHeight() const;
  bool IsOutOfBounds(const int row, const int col) const;
  Cell& GetCell(const int row, const int col);
  void SetCell(const int row, const int col, const char symbol);
  bool IsFull() const;
  bool IsEmpty() const;
  int CreatesSOS(const int row, const int col, const char symbol) const;
  void Clear();
};

#endif // SOS_INCLUDE_BOARD_H_

