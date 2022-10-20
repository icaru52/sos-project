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
  int turn_;
  //int filled_cells_;
  Cell* grid_;
  //char* grid_;

 public:
  Board(const int width, const int height);
  ~Board();
  
  int GetWidth() const;
  int GetHeight() const;
  
  bool InBounds(const int row, const int col) const;
  bool OutOfBounds(const int row, const int col) const;
  
  const Cell& GetCell(const int index) const;
  const Cell& GetCell(const int row, const int col) const;
  Cell& GetCell(const int index);
  Cell& GetCell(const int row, const int col);
  
  int CountFilledCells() const;
  int CountEmptyCells() const;
  
  bool IsFull() const;
  bool IsEmpty() const;
  
  int CreatesSOS(const int row, const int col, const char symbol) const;
  
  void Clear();
};

#endif // SOS_INCLUDE_BOARD_H_

