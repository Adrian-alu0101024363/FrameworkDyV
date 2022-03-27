#include "DyV.h"

using namespace std;

template <class P, class S>
class Quicksort : public DyV<P,S> {
public:
 Quicksort(): DyV<P,S>(){}
 ~Quicksort(){}
  S SolveSmall(P data) {
    if (data.size() == 2) {
      if (data[0] > data[1]) {
        std::swap(data[0], data[1]);
      }
    }
    S s(data.getVector());
    return s;
  }

  bool Small(P data) {
    return data.size() <= 2 ? 1 : 0; 
  }

   std::vector<P> Divide(P data, int size) {
    std::vector<P> division;
    int i = 0;
    int f = data.size() -1;
    int mid = (data.size()/2) - 1;
    auto piv = data[mid];
    while (i <= f) {
      while (data[i] <= piv) i++;
      while (data[f] > piv) f--;
      if (i <= f) {
        auto x = data[i];
        data[i] = data[f];
        data[f] = x;
        i++;
        f--;
      }
    }
    int k;
    P larr;
    auto left = larr.getVector();
    P rarr;
    auto right = rarr.getVector();
    for (k = 0; k <= f; k++) {
      left.push_back(data[k]);
    }
    for (k = i; k <= data.size() - 1; k++) {
      right.push_back(data[k]);
    }
    rarr.setVector(right);
    larr.setVector(left);
    division.push_back(larr);
    division.push_back(rarr);
    return division;
  }

  S Combine(S data1, S data2) {
    int size = data1.size() + data2.size();
    S result(size);
    int i = 0;
    for (; i < data1.size(); i++) {
      result[i] = data1[i];
    }
    int k = 0;
    for (int j = i; j < size; j++) {
      result[j] = data2[k];
      k++;
    }
    return result;
  }
  
  string getA() {return "2";}
  string getB() {return "2";}
  string getC() {return "1";}
};