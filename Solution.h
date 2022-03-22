#ifndef SOLUTION
#define SOLUTION
#include <vector>

using namespace std;

class Solution {
  vector<int> s;
  int size_;
  public:
  Solution(int size = 0){s.resize(size);size_ = size;}
  Solution(vector<int> v) {s = v; size_ = v.size();}
  int size() {return size_;}
  int& operator[](int index) {return s[index];}
  vector<int> getVector() {return s;}
  Solution operator=(Solution sol) {return Solution(sol.getVector());}
};

#endif