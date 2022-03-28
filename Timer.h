#include <time.h>
#include <iostream>
#include <string>

class Timer {
 private:
  float cpuTime_;
  float time_;
  clock_t start_;
  clock_t finish_;
 public:
  Timer(){start_ = -1;}
  ~Timer(){}
  double getCpuTime() {return cpuTime_;}
  float getTime() {return time_;}
  void setTime(float time) {time_ = time;}
  void setCpuTime(double cpuTime) {cpuTime_ = cpuTime;}
  void start() {start_ = clock();}
  void finish();
  void print(std::string timeOf);
  private:
  void convert() {cpuTime_ = (double)finish_ /CLOCKS_PER_SEC;}
};
