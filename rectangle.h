//
// Created by yi on 4/8/19.
//

#ifndef P1_RECTANGLE_H_
#define P1_RECTANGLE_H_
#include <cmath>
// This is a class which stores the coordinates of a rectangle
// It can return the area of the rectangle
class Rectangle{
 public:
  // initialize the coordinate of the rectangle
  Rectangle(int x1, int y1, int x2, int y2):x1(x1), y1(y1), x2(x2), y2(y2) {}
  // Return the area of the rectangle
  int GetArea();
  // Overload the operator "<" in order to sort rectangle instances
  bool operator < (Rectangle &rhs);

  // Coordinates of the rectangle
  int x1;
  int y1;
  int x2;
  int y2;
};
#endif    // P1_RECTANGLE_H_
