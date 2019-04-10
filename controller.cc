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

void Controller::SearchInBinary() {
  int count=0;
  std::vector<Rectangle> sorted_rect_list=SortRectangle();
  for(int i = 0; i < area_list.size();i++){
    if(BinarySearch(sorted_rect_list,area_list[i]))
      count++;
  }
  std::cout<<count<<std::endl;
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
  for(int i = 0; i < area_list.size(); i++){
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

std::vector<Rectangle> Controller::SortRectangle() {
  auto rectangle_instances=CreateRectangles();
  std::sort(rectangle_instances.begin(),rectangle_instances.end());
  return rectangle_instances;
}

bool Controller::BinarySearch(std::vector<Rectangle> &sorted_rectangle_array, int key) {
  long low = 0, high = sorted_rectangle_array.size() - 1;
  while (low <= high) {
    long mid = low + (high - low) / 2;
    if (sorted_rectangle_array[mid].GetArea() == key){
      return true;}
    if (sorted_rectangle_array[mid].GetArea() < key)
      low = mid+1;
    else
      high = mid-1;
  }
  return false;
}

std::vector<Rectangle> Controller::CreateRectangles() {
  std::vector<Rectangle> rectangle_instances;
  for(int i = 0; i < rectangle_list.size(); i++){
    rectangle_instances.emplace_back(Rectangle(rectangle_list[i][1],rectangle_list[i][2],rectangle_list[i][3],rectangle_list[i][4]));
  }
  return rectangle_instances;
}

void Controller::SearchInLinear() {
  int count=0;
  std::vector<Rectangle> rectangle_instance = CreateRectangles();
  for(int i = 0; i<area_list.size();i++){
    if(LinearSearch(rectangle_instance,area_list[i]))
      count++;
    }
  std::cout<<count<<std::endl;
  }

void Controller::PrintRectanggleArea(std::vector<Rectangle> vec) {
  for(int i = 0; i<vec.size();i++)
    std::cout<<vec[i].GetArea()<<std::endl;

}

bool Controller::LinearSearch(std::vector<Rectangle> &rectangle_array, int key) {
  for(int i =0; i < rectangle_array.size(); i++){
    if(rectangle_array[i].GetArea()==key)
      return true;
  }
  return false;
}

bool Controller::IsBinary() {
  std::cout << "Choice of search method ([l]inear, [b]inary)?" << std::endl;
  std::string user_input;
  std::cin >> user_input;
  while (user_input != "b" and user_input != "l") {
    std::cout << "Incorrect choice" << std::endl;
    std::cin >> user_input;
  }
  return user_input=="b";
}
