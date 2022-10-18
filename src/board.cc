// File: board.cc
// Project: SOS Semester Project
// Programmer: Ian Rowse

#include "board.h"

Board::Board(const int width, const int height)
{
  width_ = width;
  height_ = height;
  turn_ = 0;
  //filled_cells_ = 0;
  
  grid_ = new Cell[height_ * width_];
}

Board::~Board()
{
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

bool Board::InBounds(const int row, const int col) const
{
  return row >= 0 && row < height_ && col >= 0 && col < width_;
}

bool Board::OutOfBounds(const int row, const int col) const
{
  return row < 0 && row >= height_ && col < 0 && col >= width_;
}

Cell& Board::GetCell(const int row, const int col)
{
    return grid_[row * width_ + col];
}

const Cell& Board::GetCell(const int row, const int col) const
{
    return grid_[row * width_ + col];
}

int Board::CountFilledCells() const
{
  int filled_count = 0;

  for (int y = 0; y < height_; ++y)
  {
    for (int x = 0; x < width_; ++x)
    {
      if(!GetCell(y, x).IsEmpty())
      {
        filled_count++;
      }
    }
  }

  return filled_count;
}

int Board::CountEmptyCells() const
{
  int empty_count = 0;

  for (int y = 0; y < height_; ++y)
  {
    for (int x = 0; x < width_; ++x)
    {
      if(GetCell(y, x).IsEmpty())
      {
        empty_count++;
      }
    }
  }

  return empty_count;
}

bool Board::IsFull() const
{
  return this->CountEmptyCells() == 0;
}

bool Board::IsEmpty() const
{
  return this->CountFilledCells() == 0;
}

int Board::CreatesSOS(const int row, const int col, const char symbol) const
{
  int sos_count;

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
        
        if(InBounds(row + y_off*2, col + x_off*2))
        {
          if(GetCell(row + y_off,   col + x_off  ).IsO() && 
             GetCell(row + y_off*2, col + x_off*2).IsS())
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
        
        if((InBounds(row + y_off, col + x_off)) && 
           (InBounds(row - y_off, col - x_off)))
        {
          if(GetCell(row + y_off, col + x_off).IsS() && 
             GetCell(row - y_off, col - x_off).IsS())
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
      GetCell(y, x).SetEmpty();
    }
  }
}

