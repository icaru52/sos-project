// File: cell.h
// Project: SOS Semester Project
// Programmer: Ian Rowse

#ifndef SOSPROJECT_INCLUDE_CELL_H_
#define SOSPROJECT_INCLUDE_CELL_H_

class Cell
{
 private:
  char symbol_;

 public:
  Cell();

  char GetSymbol() const;
  void SetSymbol(const char symbol);
  bool IsEmpty() const;
  void SetEmpty();
  bool IsS() const;
  void SetS();
  bool IsO() const;
  void SetO();
};

#endif // SOSPROJECT_INCLUDE_CELL_H_

