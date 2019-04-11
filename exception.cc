//
// Created by yi on 4/8/19.
//
#include "exception.h"
void CheckInputNum(int argc) {
  if ( argc != 4 ) {
    std::cerr << "Usage: ./rectangle_search <rectangle_file.dat>"
               " <area_file.dat> <result_file.dat>" << std::endl;
    exit(0);
  }
}

void CannotOpenFile(std::string filename) {
  std::cerr << "Error: cannot open file " << filename << std::endl;
  exit(0);
}
