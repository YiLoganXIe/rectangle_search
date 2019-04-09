#include "controller.h"
int main(int argc, char *argv[]) {
  auto task_control = Controller(argc,argv);      //initialize the program
  task_control.BinarySearch();
  return 0;
}
