// File: board.cc
// Project: SOS Semester Project
// Programmer: Ian Rowse

#include "board.h"

Board::Board(const int width, const int height)
{
  width_ = width;
  height_ = height;

  for(int y = 0; y < height_; ++y)
  {
    grid_[y] = new Cell[width_];
  }
}

Board::~Board()
{
  for (int y = 0; y < height_; ++y)
  {
    delete[] grid_[y];
  }
  delete[] grid_;
}

int Board::GetWidth() const
{
  return width_;
}

int Board::GetHeight() const
{
  return height_;
}

bool Board:IsOutOfBounds(const int row, const int col) const
{
  return row > 0 && row < height_ && col > 0 && col < width_;
}

Cell& Board::GetCell(const int row, const int col)
{
  // Just don't do it. :)
  //if(row >= 0 && row < height_ && col >= 0 && col < width_)
  //{
    return grid_[row][col];
  //}
}

bool Board::IsFull() const
{
  bool is_full = true;

  for (int y = 0; y < height_; ++y)
  {
    for (int x = 0; x < width_; ++x)
    {
      if(grid_[y][x].IsEmpty())
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
      if(!grid_[y][x].IsEmpty())
      {
        is_empty = false;
      }
    }
  }

  return is_empty;
}

int Board::CreatesSOS(const int row, const int col, const char symbol) const
{
  bool sos_count;

  const int offsets[8][2] = {
    {-1,-1}, // north west
    {-1, 0}, // north
    {-1, 1}, // north east
    { 0, 1}, //       east
    { 1, 1}, // south east
    { 1, 0}, // south
    { 1,-1}, // south west
    { 0,-1}, //       west
  };

  switch(symbol)
  {
    case 'S':
      for(int i = 0; i < 8; ++i)
      {
        int y_off = offsets[i][0];
        int x_off = offsets[i][1];
        
        if(!IsOutOfBounds(row + y_off*2, col + x_off*2))
        {
          if(grid_[row + y_off  ][col + x_off  ].IsO() && 
             grid_[row + y_off*2][col + x_off*2].IsS())
          {
            ++sos_count;
          }
        }
      }

      break;

    case 'O':
      for(int i = 0; i < 4; ++i)
      {
        int y_off = offsets[i][0];
        int x_off = offsets[i][1];
        
        if((!IsOutOfBounds(row + y_off, col + x_off)) && 
           (!IsOutOfBounds(row - y_off, col - x_off)))
        {
          if(grid_[row + y_off][col + x_off].IsS() && 
             grid_[row - y_off][col - x_off].IsS())
          {
            ++sos_count;
          }
        }
      }

      break;

    //case ' ':
    default:
      sos_count = 0;
      break;
  }

  return sos_count;
}

void Board::Clear()
{
  for (int y = 0; y < height_; ++y)
  {
    for (int x = 0; x < width_; ++x)
    {
      grid_[y][x].SetEmpty();
    }
  }
}

