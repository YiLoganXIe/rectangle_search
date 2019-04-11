//
// Created by yi on 4/8/19.
//
#include "controller.h"
Controller::Controller(int argc, char *argv[]) {
  CheckInputNum(argc);
  ReadInputFile(argv);
  logfile_name = argv[3];
}

void Controller::ReadInputFile(char *argv[]) {
  ReadRectangle(argv[1]);
  ReadArea(argv[2]);
}

void Controller::ReadRectangle(std::string filename) {
  std::string line;
  std::ifstream input_file;
  input_file.open(filename);
  if ( input_file.is_open() ) {
    while ( getline (input_file, line) )
      rectangle_list.push_back(Spilt(line));
  } else {
    CannotOpenFile(filename);
  }
}

void Controller::ReadArea(std::string filename) {
  std::string line;
  std::ifstream input_file;
  input_file.open(filename);
  if ( input_file.is_open() ) {
    while ( getline(input_file, line) ) {
      area_list.push_back(std::stoi(line));
    }
  } else {
    CannotOpenFile(filename);
  }
}

std::vector<int> Controller::Spilt(std::string line) {
  std::vector<int> res;
  // add a space to the end of the string in order to find the last number
  std::string template_string = line + " ";
  size_t pos = template_string.find(" ");
  while (pos != template_string.npos) {
    std::string temp = template_string.substr(0, pos);
    // transform the string into int
    res.push_back(std::stoi(temp));
    // update the string need to be processed
    template_string = template_string.substr(pos+1, template_string.size());
    pos = template_string.find(" ");
  }
  return res;
}

std::vector<Rectangle> Controller::CreateRectangles() {
  std::vector<Rectangle> rectangle_instances;
  for (int i = 0; i < rectangle_list.size(); i++) {
    rectangle_instances.push_back(Rectangle(rectangle_list[i][0],
        rectangle_list[i][1], rectangle_list[i][2], rectangle_list[i][3]));
  }
  return rectangle_instances;
}

std::vector<Rectangle> Controller::SortRectangle() {
  auto rectangle_instances = CreateRectangles();
  std::sort(rectangle_instances.begin(), rectangle_instances.end());
  return rectangle_instances;
}

bool Controller::IsBinary() {
  std::cout << "Choice of search method ([l]inear, [b]inary)?" << std::endl;
  std::string user_input;
  std::cin >> user_input;
  while (user_input != "b" && user_input != "l") {
    std::cerr << "Incorrect choice" << std::endl;
    std::cin >> user_input;
  }
  return user_input == "b";
}

void Controller::SearchInBinary() {
  int count = 0;
  std::vector<Rectangle> sorted_rect_list = SortRectangle();
  for (int i = 0; i < area_list.size(); i++) {
    if (BinarySearch(sorted_rect_list, area_list[i]))
      count++;
  }
  CreateLog(count);
}

bool Controller::BinarySearch(std::vector<Rectangle>
    &sorted_rectangle_array, int key) {
  int low = 0, high = sorted_rectangle_array.size() - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (sorted_rectangle_array[mid].GetArea() == key) {
      return true;
    } else if (sorted_rectangle_array[mid].GetArea() < key) {
      low = mid+1;
    } else {
      high = mid - 1;
    }
  }
  return false;
}


void Controller::SearchInLinear() {
  int count = 0;
  std::vector<Rectangle> rectangle_instance = CreateRectangles();
  for (int i = 0; i < area_list.size(); i++) {
    if (LinearSearch(rectangle_instance, area_list[i]))
      count++;
  }
  CreateLog(count);
}

bool Controller::LinearSearch(std::vector<Rectangle>
    &rectangle_array, int key) {
  for (int i = 0; i < rectangle_array.size(); i++) {
    if (rectangle_array[i].GetArea() == key)
      return true;
  }
  return false;
}

void Controller::CreateLog(int result) {
  std::ofstream logfile;
  logfile.open(logfile_name);
  if (logfile.is_open()) {
    logfile << result;
    logfile.close();
  } else {
    CannotOpenFile(logfile_name);
  }
}
