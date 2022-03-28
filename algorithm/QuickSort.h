#include "../DyV.h"

using namespace std;

template <class P, class S>
class Quicksort : public DyV<P,S> {
  public:
  Quicksort(): DyV<P,S>(){}
  ~Quicksort(){}
 /**
  * @brief If the data was small (checked with Small) check if the bigger
  * value is in the position 0 or 1 and swap if needed
  * @param data 
  * @return S 
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
   * by the pivot (middle value of array)
   * @param data the original problem
   * @param size the size of the problem (no use)
   * @return std::vector<P> the two subproblems
   */
  std::vector<P> Divide(P data, int size) {
  std::vector<P> division;
  int i = 0;
  int f = data.size() -1;
  int mid = (data.size()/2) - 1;
  auto piv = data[mid];
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

  /**
   * @brief Combine the subsolution
   * 
   * @param data1 the first subsolution
   * @param data2 the second subsolution
   * @return S the sorted combined solution 
   */
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