// File: board.cc
// Project: SOS Semester Project
// Programmer: Ian Rowse

#include "board.h"

Board::Board(int width, int height)
{
  width_ = width;
  height_ = height;

  for(int y = 0; y < height_; ++y)
  {
    board_[y] = new Cell[width_];
  }
}

Board::~Board()
{
  for (int y = 0; y < height_; ++y)
  {
    delete[] board_[y];
  }
  delete[] board_;
}

int Board::GetWidth() const
{
  return width_;
}

int Board::GetHeight() const
{
  return height_;
}

Cell Board::GetCell(int row, int col)
{
  // Just don't do it. :)
  //if(row >= 0 && row < height_ && col >= 0 && col < width_)
  //{
    return board_[row][col];
  //}
}

bool Board::IsFull() const
{
  bool is_full = true;

  for (int y = 0; y < height_; ++y)
  {
    for (int x = 0; x < width_; ++x)
    {
      if(board_.GetCell(y, x)->IsEmpty())
      {
        is_full = false;
      }
    }
  }

  return is_full;
}

bool Board::IsEmpty() const
{
  bool is_empty = true;

  for (int y = 0; y < height_; ++y)
  {
    for (int x = 0; x < width_; ++x)
    {
      if(!board_.GetCell(y, x)->IsEmpty())
      {
        is_empty = false;
      }
    }
  }

  return is_empty;
}

void Board::Clear()
{
  for (int y = 0; y < height_; ++y)
  {
    for (int x = 0; x < width_; ++x)
    {
      board_.GetCell(y, x)->SetEmpty();
    }
  }
}

