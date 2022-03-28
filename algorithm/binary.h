#include "../DyV.h"

using namespace std;

template <class P, class S>
class Binary : public DyV<P,S> {

  public:
  Binary(): DyV<P,S>(){}
  ~Binary(){}
  /**
   * @brief If the data was small (checked with Small) check if the value 
   * is either on the first position or the second one
   * @param data the given problem 
   * @return S the solution to the problem
   */
  S SolveSmall(P data) {
    S s(data.getVector());
    auto value = data.getValue();
    if (data[0] == value) {
      s.setFounded(1);
      return s;
    } 
    if (data[1] == value) {
      s.setFounded(1);    
      return s;
    }
    s.setFounded(0);
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
    * @brief Divide the given problem in two subproblems dependen 
    *  on the value at the center of the array
    * @param data the original problem
    * @param size the size of the problem (no use)
    * @return std::vector<P> the two subproblems
    */
   std::vector<P> Divide(P data, int size) {
    std::vector<P> division;
    int mid = (data.size() / 2) - 1;
    P larr;
    P rarr;
    auto right = rarr.getVector();
    auto left = larr.getVector();
    larr.setValue(data.getValue());
    rarr.setValue(data.getValue());
    if (data[mid] == data.getValue()) {
      right.push_back(data[mid]);
      left.push_back(data[mid]);
      rarr.setVector(right);
      larr.setVector(left);
      division.push_back(larr);
      division.push_back(rarr);
      return division;
    }
    if (data[mid] > data.getValue()) {
      for (int i = 0; i < mid/2; i++) {
        left.push_back(data[i]);
      }
      for (int j = mid /2; j < mid; j++) {
        right.push_back(data[j]);
      }
      rarr.setVector(right);
      larr.setVector(left);
      division.push_back(larr);
      division.push_back(rarr);
      return division;
    } else {
      int limit = data.size() - mid + 1; 
      int kuso = mid + limit/2;
      for (int i = mid + 1; i < kuso; i++) {
        left.push_back(data[i]);
      }
      for (int j = kuso; j < data.size(); j++) {
        right.push_back(data[j]);
      }
      rarr.setVector(right);
      larr.setVector(left);
      division.push_back(larr);
      division.push_back(rarr);
      return division;
    }
    return division;
  }

  /**
   * @brief Combine the subsolution in one if the
   * value is found then it's set in S as founded
   * @param data1 the second subsolution
   * @param data2 the second subsolution
   * @return S the combined solution
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
    if (data1.getFounded() || data2.getFounded()) {
      result.setFounded(1);
    }
    return result;
  }
  string getA() {return "1";}
  string getB() {return "2";}
  string getC() {return "1";}
};