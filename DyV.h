#ifndef DYV
#define DYV
#include <utility>
#include <iostream>

template <class T>
class DyV {

 public:
  DyV(){}
  virtual ~DyV(){}
  T Solve(T data, int l, int r) {
    T S;
    if (Small(data)) {
      std::cout << "Small data";
      return SolveSmall(data);
    } else {
      std::pair<T,T> problem = Divide(data, l, r);
      problem.first = Solve(problem.first, l, problem.first.size()-1);
      //T S2 = Solve(problem.second, 0, problem.second.size()-1);
      std::cout << std::endl << "Size: " << problem.first.size() << std::endl;
      std::cout << "problem first" << std::endl; 
      for (int i = 0; i < problem.first.size(); i++) {
        std::cout << problem.first[i];
      }
      std::cout << std::endl << "problem second" << std::endl; 
      for (int i = 0; i < problem.first.size(); i++) {
        std::cout << problem.second[i];
      }
      //S = Combine(S1, S2);
      std::cout << std::endl << "S" << std::endl;
      if (S.size() > 0) {
        std::cout << "mayor";
        for (int i = 0; i < problem.first.size(); i++) {
          std::cout << S[i];
        } 
      }
      return S;
    }
  }

  virtual bool Small(T data) = 0;
  virtual T SolveSmall(T data) = 0;
  virtual std::pair<T,T> Divide(T data, int l, int r) = 0;
  virtual T Combine(T data1, T data2) = 0;
};
#endif