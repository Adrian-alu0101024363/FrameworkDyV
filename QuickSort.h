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
    auto piv = data[(i + f + 1)/2];
    std::cout << "Pivote " << piv << std::endl;
    while (i <= f) {
      while (data[i] < piv) i++;
      while (data[f] > piv) f--;
      if (i <= f) {
        auto x = data[i];
        data[i] = data[f];
        data[f] = x;
        i++;
        f--;
      }
    }
    std::cout << "Data esta: " << std::endl;
    for (int m = 0; m < data.size(); m++) {
      std::cout << data[m] << " ";
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
    std::cout << "Right esta: " << std::endl;
    for (int m = 0; m < rarr.size(); m++) {
      std::cout << rarr[m] << " ";
    }
    std::cout << "Left esta: " << std::endl;
    for (int m = 0; m < larr.size(); m++) {
      std::cout << larr[m] << " ";
    }
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
    std::cout << "Result size: " << result.size() << std::endl;
    for (int i = 0; i < result.size(); i++) {
      std::cout << result[i] << " ";
    }
    
    return result;
  }
};