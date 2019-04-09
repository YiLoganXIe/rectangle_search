//
// Created by yi on 4/8/19.
//
#include "controller.h"
Controller::Controller(int argc, char *argv[]) {
  CheckInputNum(argc);
  ReadInputFile(argv);
}

void Controller::ReadInputFile(char *argv[]) {
    ReadRectangle(argv[1]);
    ReadArea(argv[2]);
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

void Controller::ReadArea(std::string filename) {
  std::string line;
  std::ifstream input_file;
  input_file.open(filename);
  if(input_file.is_open()){
    while ( getline (input_file,line) )
    {
      area_list.push_back(std::stoi(line));
    }
  }
  else{
    CannotOpenFile(filename);
  }
}

void Controller::PrintRectangleList() {
  for(int i = 0; i < rectangle_list.size(); i++){
    for(int j = 0; j < 4; j++){
      std::cout<<rectangle_list[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
}
void Controller::PrintAreaList() {
  for(int i = 0; i < rectangle_list.size(); i++){
    std::cout<<area_list[i]<<std::endl;
  }
}

std::vector<std::vector<int>> Controller::GetRectangleList() {
  return rectangle_list;
}
std::vector<int> Controller::GetAreaList() {
  return area_list;
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



