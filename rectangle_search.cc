#include "controller.h"
using std::chrono::high_resolution_clock;
using std::chrono::microseconds;
using std::chrono::duration_cast;
int main(int argc, char *argv[]) {
  auto task_control = Controller(argc, argv);
  high_resolution_clock::time_point beginTime;
  if ( task_control.IsBinary() ) {
    // Start Record the Time
    beginTime = high_resolution_clock::now();
    task_control.SearchInBinary();
  } else {
    // Start Record the Time
    beginTime = high_resolution_clock::now();
    task_control.SearchInLinear();
  }
  // Stop the timer
  high_resolution_clock::time_point endTime = high_resolution_clock::now();
  // Calculate the time duration
  microseconds timeInterval = duration_cast<microseconds>(endTime - beginTime);
  std::cout <<"CPU time: "<< timeInterval.count() << " microseconds\n";
  return 0;
}
