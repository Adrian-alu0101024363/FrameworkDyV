#ifndef VECTOR
#define VECTOR
#include <vector>

using namespace std;

class Vector {
  vector<int> p;
  int size_;
  public:
  Vector(){size_ = 0;}
  Vector(int size){p.resize(size);size_ = size;}
  Vector(vector<int> v) {p = v; size_ = v.size();}
  int size() {return size_;}
  int& operator[](int index) {return p[index];}
  vector<int> getVector(){ return p;}
  void setVector(vector<int> v) { p = v; size_ = v.size();} 
};
#endif