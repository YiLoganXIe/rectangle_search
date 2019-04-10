#include "controller.h"
int main(int argc, char *argv[]) {
  auto task_control = Controller(argc,argv);      //initialize the program
  if(task_control.IsBinary())
    task_control.SearchInBinary();
  else
    task_control.SearchInLinear();

  return 0;
}
