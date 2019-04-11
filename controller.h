//
// Created by yi on 4/8/19.
//

#ifndef P1_CONTROLLER_H_
#define P1_CONTROLLER_H_
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include "exception.h"
#include "rectangle.h"
// A controller that split the task into parts
// It stores the input data as vectors
class Controller{
 public:
  // Initialize the controller and read the input file
  // Change the file content into a vector and store it
  Controller(int argc, char*argv[]);
  // Use Binary search to search the area-rectangle pair
  void SearchInBinary();
  // Call rectangle constructer to return a list of rectangle instance
  std::vector<Rectangle> CreateRectangles();
  // Use Linear Search to search the area-rectangle pair
  void SearchInLinear();
  // let the user input the algorithm which need to be used
  bool IsBinary();

 private:
  // read the files
  void ReadInputFile(char*argv[]);
  // read rectangle file
  void ReadRectangle(std::string filename);
  // read area file
  void ReadArea(std::string filename);
  // Binary Search Algorithm
  bool BinarySearch(std::vector<Rectangle> &sorted_rectangle_array, int key);
  // Linear Search Algorithm
  bool LinearSearch(std::vector<Rectangle> &rectangle_array, int key);
  // create a log to record the result
  void CreateLog(int result);
  // sort the rectangle by its area
  std::vector<Rectangle> SortRectangle();
  // split the line to get each number
  std::vector<int> Spilt(std::string line);

  // A list of area which get from input
  std::vector<int> area_list;
  // A list of list of integer which store the coordinate for each rectangle
  std::vector<std::vector<int>> rectangle_list;
  // The name of the output file
  std::string logfile_name;
};
#endif    // P1_CONTROLLER_H_
