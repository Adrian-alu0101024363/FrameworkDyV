#include "../DyV.h"

using namespace std;

template <class P, class S>
class MergeSort : public DyV<P,S> {
 public:
  MergeSort(): DyV<P,S>(){}
  ~MergeSort(){}
  /**
   * @brief If the data was small (checked with Small) check if the bigger
   * value is in the position 0 or 1 and swap if needed
   * @param data the given problem 
   * @return S the solution to the problem
   */
  S SolveSmall(P data) {
    if (data.size() == 2) {
      if (data[0] > data[1]) {
        std::swap(data[0], data[1]);
      }
    }
    S s(data.getVector());
    return s;
  }

  /**
   * @brief Check if we are searching a value in 
   * a subvector of size 2 or less
   * @param data the given problem 
   * @return true 
   * @return false 
   */
  bool Small(P data) {
    return data.size() <= 2 ? 1 : 0; 
  }

  /**
   * @brief Divide the given problem in two subproblems 
   * by half
   * @param data the original problem
   * @param size the size of the problem (no use)
   * @return std::vector<P> the two subproblems
   */
  std::vector<P> Divide(P data, int size) {
    std::vector<P> division;
    int nl, nr;
    int m = (data.size() / 2);
    nl = m + 1;
    nr = data.size() - m - 1;
    P larr;
    auto left = larr.getVector();
    P rarr;
    auto right = rarr.getVector();
    for(int i = 0; i < nl; i++) {
      left.push_back(data[i]);
    }
    for(int j = 0; j < nr; j++) {
      right.push_back(data[m + j + 1]);
    }
    rarr.setVector(right);
    larr.setVector(left);
    division.push_back(larr);
    division.push_back(rarr);
    return division;
  }

  /**
   * @brief Combine the subsolution sorting the elements
   * @param data1 the first subsolution
   * @param data2 the second subsolution
   * @return S the sorted solution 
   */
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