//
// Created by yi on 4/8/19.
//

#ifndef RECTANGLE_SEARCH_CONTROLLER_H
#define RECTANGLE_SEARCH_CONTROLLER_H
#include <stdlib.h>
#include <vector>
#include <string>
// A controller that split the task into parts
// It stores the input data as vectors

class Controller{
 public:

  //Initialize the controller and read the input file
  //Change the file content into a vector and store it
  Controller(int argc, char*argv[]);

  //Get a vector that contains areas
  void GetAreaList();

  //Get a vector that contains rectangle coordinates
  std::vector<std::vector<int>> GetRectangleList();

  //Print out rectangle list
  void PrintRectangleList();
 private:
  //check the number of the arguments
  void CheckInputNum(int argc);
  //read the files
  void ReadInputFile(char*argv[]);
  //read rectangle file
  void ReadRectangle(std::string filename);

  void CannotOpenFile(std::string filename);
  //split the line to get each number
  std::vector<int> Spilt(std::string line);

  std::vector<int> area_list;
  std::vector<std::vector<int>> rectangle_list;
};
#endif //RECTANGLE_SEARCH_CONTROLLER_H
