#include "DyV.h"

template <class T>
class MergeSort : public DyV<T> {
 private:
 
 public:
  //MergeSort(): DyV(){}
  bool Small(T data) {
    return data.size() <= 0 ? 1 : 0; 
  }
  ~MergeSort(){}
  T SolveSmall(T data) {
    return data;
  }

  std::pair<T,T> Divide(T data, int l, int r) {
    std::pair<T,T> division;
    int i, j, k, nl, nr;
    int m = l + (r -l) / 2;
    nl = m - l + 1;
    nr = r - m;
    T larr(nl);
    T rarr(nr);
    for(i = 0; i < nl; i++) {
      larr[i] = data[l + i];
    }
    for(j = 0; j < nr; j++) {
      rarr[j] = data[m + 1 + j];
    }
    division.first = larr;
    division.second = rarr;
    return division;
  }

  T Combine(T data1, T data2) {
    int i = 0; 
    int j = 0;
    int k = 0;
    T result(data1.size() + data2.size());
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
    std::cout << "Size es : " << data1.size();
    std::cout << "Left array tiene: " << std::endl;
    for (int l = 0; l < data1.size(); l++) {
      std::cout << data1[l];
    }
     std::cout << std::endl << "Right array tiene: " << std::endl;
    for(int s = 0; s < data2.size(); s++) {
      std::cout << data2[s];
    }
    return result;
  }
};