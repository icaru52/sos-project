// File: board.h
// Project: SOS Semester Project
// Programmer: Ian Rowse

#ifndef SOS_INCLUDE_BOARD_H_
#define SOS_INCLUDE_BOARD_H_

class Board
{
 private:
  int height_;
  int width_;
  int turn_;
  int marked_cells_;
  char* grid_;

 public:
  Board(const int width, const int height);
  ~Board();
  
  int GetWidth() const;
  int GetHeight() const;
  
  bool InBounds(const int row, const int col) const;
  bool OutOfBounds(const int row, const int col) const;

  char GetMark(const int row, const int col) const;
  bool SetMark(const int row, const int col, const char mark);
  bool MarkIs(const int row, const int col, const char mark) const;

  int CountMarkedCells() const;
  int CountUnmarkedCells() const;
  
  bool IsFull() const;
  bool IsEmpty() const;
  
  int CreatesSOS(const int row, const int col, const char symbol) const;
  
  void Clear();
};

#endif // SOS_INCLUDE_BOARD_H_

