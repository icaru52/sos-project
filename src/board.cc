// File: board.cc
// Project: SOS Semester Project
// Programmer: Ian Rowse

#include "board.h"

Board::Board(const int width, const int height)
{
  height_ = height;
  width_ = width;
  mark_count_ = 0;
  turn_ = 0;
  
  grid_ = new char[height * width];

  for(int i = 0; i < height * width; ++i)
  {
    grid_[i] = ' ';
  }
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

int Board::GetMarkCount() const
{
  return mark_count_;
}

int Board::GetUnmarkedCount() const
{
  return height_ * width_ - mark_count_;
}

bool Board::InBounds(const int row, const int col) const
{
  return row >= 0 && 
         row < height_ && 
         col >= 0 && 
         col < width_;
}

bool Board::OutOfBounds(const int row, const int col) const
{
  return row < 0 && 
         row >= height_ && 
         col < 0 && 
         col >= width_;
}

char Board::GetMark(const int row, const int col) const
{
  return grid_[row * width_ + col];
}

bool Board::SetMark(const int row, const int col, const char mark)
{
  if(!this->MarkIs(row, col, ' '))
  {
    // The space already contains a character
    return false;
  }
  else if(mark != 'S' && mark != 'O')
  {
    // The mark is not valid
    return false;
  }
  else
  {
    grid_[row * width_ + col] = mark;
    mark_count_++;
    return true;
  }
}

bool Board::MarkIs(const int row, const int col, const char mark) const
{
  if(OutOfBounds(row, col))
  {
    return false;
  }
  else
  {
    return grid_[row * width_ + col] == mark;
  }
}

bool Board::IsFull() const
{
  return mark_count_ == height_ * width_;
}

bool Board::IsEmpty() const
{
  return mark_count_ == 0;
}

int Board::CreatesSOS(const int row, const int col, const char mark) const
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

  switch(mark)
  {
    case 'S':
      for(int i = 0; i < 8; ++i)
      {
        int y_off = offsets[i][0];
        int x_off = offsets[i][1];
        
        if(InBounds(row + y_off*2, col + x_off*2))
        {
          if(MarkIs(row + y_off,   col + x_off  , 'O') && 
             MarkIs(row + y_off*2, col + x_off*2, 'S'))
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
          if(MarkIs(row + y_off, col + x_off, 'S') && 
             MarkIs(row - y_off, col - x_off, 'S'))
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
  for (int i = 0; i < height_ * width_; ++i)
  {
    grid_[i] = ' ';
  }
  mark_count_ = 0;
}

