//
// Created by yi on 4/8/19.
//

#ifndef RECTANGLE_SEARCH_CONTROLLER_H
#define RECTANGLE_SEARCH_CONTROLLER_H
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

  //Initialize the controller and read the input file
  //Change the file content into a vector and store it
  Controller(int argc, char*argv[]);

  //Get a vector that contains areas
  std::vector<int> GetAreaList();

  //Get a vector that contains rectangle coordinates
  std::vector<std::vector<int>> GetRectangleList();
  //Use Binary search to search the area-rectangle pair
  void SearchInBinary();

  std::vector<Rectangle> CreateRectangles();
  //Use Linear Search to search the area-rectangle pair
  void SearchInLinear();
  //let the user input the algorithm which need to be used
  bool IsBinary();
  //Print out area list             #just for test
  void PrintAreaList();
  //Print out rectangle list        #just for test
  void PrintRectangleList();
  //Print out Sorted rectangle area       #just for test
  void PrintRectanggleArea(std::vector<Rectangle> vec);

 private:
  //read the files
  void ReadInputFile(char*argv[]);
  //read rectangle file
  void ReadRectangle(std::string filename);
  //read area file
  void ReadArea(std::string filename);
  //Binary Search Algorithm
  bool BinarySearch(std::vector<Rectangle> &sorted_rectangle_array,int key);
  //Linear Search Algorithm
  bool LinearSearch(std::vector<Rectangle> &rectangle_array,int key);
  //create a log to record the result
  void CreateLog(int result);



  std::vector<Rectangle> SortRectangle();

  //split the line to get each number
  std::vector<int> Spilt(std::string line);

  std::vector<int> area_list;
  std::vector<std::vector<int>> rectangle_list;
  std::string logfile_name;
};
#endif //RECTANGLE_SEARCH_CONTROLLER_H
