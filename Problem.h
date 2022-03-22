#ifndef PROBLEM
#define PROBLEM
#include <vector>

using namespace std;

class Problem {
  vector<int> p;
  int size_;
  public:
  Problem(){size_ = 0;}
  Problem(int size){p.resize(size);size_ = size;}
  Problem(vector<int> v) {p = v; size_ = v.size();}
  int size() {return size_;}
  int& operator[](int index) {return p[index];}
  vector<int> getVector(){ return p;}
};
#endif