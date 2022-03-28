#ifndef VECTORBINARY
#define VECTORBINARY
#include <vector>

using namespace std;

class Vectorbinary {
  int value_;
  vector<int> p;
  int size_;
  bool founded_ = 0;
  public:
  Vectorbinary(){size_ = 0;}
  Vectorbinary(int size){p.resize(size);size_ = size;}
  Vectorbinary(vector<int> v) {p = v; size_ = v.size();}
  int size() {return size_;}
  int& operator[](int index) {return p[index];}
  vector<int>& getVector(){ return p;}
  void setVector(vector<int> v) { p = v; size_ = v.size();}
  void setValue(int value) {value_ = value;}
  int getValue() {return value_;}
  bool getFounded() {return founded_;} 
  void setFounded(bool founded) {founded_ = founded;}
};
#endif