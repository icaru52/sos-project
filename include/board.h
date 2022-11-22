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
  int mark_count_;
  int turn_;
  char* grid_;

 public:
  Board(const int height = 8, const int width = 8);
  ~Board();
  
  int GetWidth() const;
  int GetHeight() const;
  
  int GetMarkCount() const;
  int GetUnmarkedCount() const;

  bool InBounds(const int row, const int col) const;
  bool OutOfBounds(const int row, const int col) const;

  char GetMark(const int row, const int col) const;
  bool SetMark(const int row, const int col, const char mark);
  bool MarkIs(const int row, const int col, const char mark) const;
  
  bool IsFull() const;
  bool IsEmpty() const;
  
  int CreatesSOS(const int row, const int col, const char mark) const;
  
  void Clear();
  void Reset(const int height, const int width);
};

#endif // SOS_INCLUDE_BOARD_H_

