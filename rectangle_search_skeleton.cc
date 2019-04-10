#include "controller.h"
using std::chrono::high_resolution_clock;
using std::chrono::microseconds;
int main(int argc, char *argv[]) {
  auto task_control = Controller(argc,argv);      //initialize the program
  high_resolution_clock::time_point beginTime;
  if(task_control.IsBinary()){
    beginTime= high_resolution_clock::now();
    task_control.SearchInBinary();
  }else {
    beginTime = high_resolution_clock::now();
    task_control.SearchInLinear();
  }
  high_resolution_clock::time_point endTime = high_resolution_clock::now();
  microseconds timeInterval = std::chrono::duration_cast<microseconds>(endTime - beginTime);
  std::cout <<"CPU time: "<< timeInterval.count() << " microseconds\n";
  return 0;
}
