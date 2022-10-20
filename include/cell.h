// File: cell.h
// Project: SOS Semester Project
// Programmer: Ian Rowse

#ifndef SOS_INCLUDE_CELL_H_
#define SOS_INCLUDE_CELL_H_

class Cell
{
 private:
  char mark_;

 public:
  Cell();

  char GetMark() const;
  void SetMark(const char mark);
  bool MarkIs(const char mark) const;

  void SetEmpty();
  void SetS();
  void SetO();
};

#endif // SOS_INCLUDE_CELL_H_

