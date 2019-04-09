//
// Created by yi on 4/8/19.
//
#include <iostream>
#include <fstream>
#include "controller.h"
Controller::Controller(int argc, char *argv[]) {
  CheckInputNum(argc);
  ReadInputFile(argv);

}


void Controller::CheckInputNum(int argc) {
  if(argc != 4){
    std::cerr<<"Usage: rectangle_search_reference <rectangle_file.dat> <area_file.dat> <result_file.dat>"<<std::endl;
    exit(0);
  }
}

void Controller::ReadInputFile(char *argv[]) {
    std::string line;
  std::ifstream input_file;
    input_file.open(argv[1]);
    if(input_file.is_open()){
      while ( getline (input_file,line) )
      {
        rectangle_list.push_back(Spilt(line));
      }
    }
    else{
      std::cerr<<"Error: cannot open file " << argv[1] << std::endl;
      exit(0);
    }

  input_file.close();

}

void Controller::PrintRectangleList() {
  for(int i = 0; i < rectangle_list.size(); i++){
    for(int j = 0; j < 4; j++){
      std::cout<<rectangle_list[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
}

std::vector<int> Controller::Spilt(std::string line) {
  std::vector<int> res;
  std::string template_string = line + " ";
  size_t pos = template_string.find(" ");

  while(pos != template_string.npos)
  {
    std::string temp = template_string.substr(0, pos);
    res.push_back(std::stoi(temp));
    template_string = template_string.substr(pos+1, template_string.size());
    pos = template_string.find(" ");
  }

  return res;
}

std::vector<std::vector<int>> Controller::GetRectangleList() {
  return rectangle_list;
}

void Controller::ReadRectangle(std::string filename) {
  std::string line;
  std::ifstream input_file;
  input_file.open(filename);
  if(input_file.is_open()){
    while ( getline (input_file,line) )
    {
      rectangle_list.push_back(Spilt(line));
    }
  }
  else{
    CannotOpenFile(filename);
  }

}

void Controller::CannotOpenFile(std::string filename) {
  std::cerr<<"Error: cannot open file " << filename << std::endl;
  exit(0);
}

