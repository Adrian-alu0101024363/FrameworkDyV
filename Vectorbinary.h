#ifndef VECTORBINARY
#define VECTORBINARY
#include <vector>

using namespace std;

class Vectorbinary {
  float value_;
  vector<float> p;
  int size_;
  bool founded_ = 0;
  public:
  Vectorbinary(){size_ = 0;}
  Vectorbinary(int size){p.resize(size);size_ = size;}
  Vectorbinary(vector<float> v) {p = v; size_ = v.size();}
  int size() {return size_;}
  float& operator[](int index) {return p[index];}
  vector<float>& getVector(){ return p;}
  void setVector(vector<float> v) { p = v; size_ = v.size();}
  void setValue(float value) {value_ = value;}
  float getValue() {return value_;}
  bool getFounded() {return founded_;} 
  void setFounded(bool founded) {founded_ = founded;}
};
#endif