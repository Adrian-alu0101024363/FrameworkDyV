#include "DyV.h"

using namespace std;

template <class P, class S>
class Binary : public DyV<P,S> {
private:
bool founded_;
public:
 Binary(): DyV<P,S>(){}
 ~Binary(){}
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

  bool Small(P data) {
    return data.size() <= 2 ? 1 : 0; 
  }

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