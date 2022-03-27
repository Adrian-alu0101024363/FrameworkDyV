#include "DyV.h"

using namespace std;

template <class P, class S>
class MergeSort : public DyV<P,S> {
 public:
  MergeSort(): DyV<P,S>(){}
  ~MergeSort(){}
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
    if (size > 2) {
    int i, j, k, nl, nr;
    int m = size / 2;
    nl = m + 1;
    nr = size - m;
    P larr(nl);
    P rarr(nr);
    for(i = 0; i < nl; i++) {
      larr[i] = data[i];
    }
    for(j = 0; j < nr; j++) {
      rarr[j] = data[m + 1 + j];
    }
    division.push_back(larr);
    division.push_back(rarr);
    }
    return division;
  }

  S Combine(S data1, S data2) {
    int i = 0; 
    int j = 0;
    int k = 0;
    S result(data1.size() + data2.size());
    while(i < data1.size() && j < data2.size()) {
      if (data1[i] <= data2[j]) {
        result[k] = data1[i];
        i++;
      } else {
        result[k] = data2[j];
        j++;
      }
      k++;
    }
    while (i < data1.size()) {
      result[k] = data1[i];
      i++;k++;
    }
    while (j < data2.size()) {
      result[k] = data2[j];
      j++;k++;
    }
    return result;
  }
  string getA() {return "2";}
  string getB() {return "2";}
  string getC() {return "1";}
};