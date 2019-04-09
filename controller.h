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
#include "exception.h"
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

  //Print out area list             #just for test
  void PrintAreaList();
  //Print out rectangle list        #just for test
  void PrintRectangleList();

 private:
  //read the files
  void ReadInputFile(char*argv[]);
  //read rectangle file
  void ReadRectangle(std::string filename);
  //read area file
  void ReadArea(std::string filename);

  //split the line to get each number
  std::vector<int> Spilt(std::string line);

  std::vector<int> area_list;
  std::vector<std::vector<int>> rectangle_list;
};
#endif //RECTANGLE_SEARCH_CONTROLLER_H
