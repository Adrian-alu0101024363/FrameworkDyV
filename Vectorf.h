#ifndef VECTORF
#define VECTORF
#include <vector>

using namespace std;

class Vectorf {
  vector<float> p;
  int size_;
  public:
  Vectorf(){size_ = 0;}
  Vectorf(int size){p.resize(size);size_ = size;}
  Vectorf(vector<float> v) {p = v; size_ = v.size();}
  int size() {return size_;}
  float& operator[](int index) {return p[index];}
  vector<float>& getVector(){ return p;}
  void setVector(vector<float> v) { p = v; size_ = v.size();} 
};
#endif