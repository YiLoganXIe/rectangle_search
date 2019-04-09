//
// Created by yi on 4/8/19.
//

#ifndef RECTANGLE_SEARCH_RECTANGLE_H
#define RECTANGLE_SEARCH_RECTANGLE_H
#include <cmath>
//This is a class which stores the coordinates of a rectangle
//It can return the area of the rectangle
class Rectangle{
 public:
  //initialize the coordinate of the rectangle
  Rectangle(int x1,int y1, int x2, int y2):x1(x1),y1(y1),x2(x2),y2(y2){};

  int GetArea();

  int x1;
  int y1;
  int x2;
  int y2;
  bool operator < (Rectangle &rhs);
};
#endif //RECTANGLE_SEARCH_RECTANGLE_H
