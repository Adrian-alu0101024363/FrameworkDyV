#ifndef PROBLEM
#define PROBLEM
#include <vector>

using namespace std;

class Problem {
  public:
  //Problem() = 0;
  //Problem(int size);
  //Problem(T v);
  virtual int size() = 0;
  //virtual int& operator[](int index) = 0;
  //virtual vector<int> getVector() = 0;
  //virtual vector<float> getVector() = 0;
};
#endif