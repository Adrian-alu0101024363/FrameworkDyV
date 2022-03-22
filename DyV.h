#ifndef DYV
#define DYV
#include <utility>
#include <iostream>
#include "Solution.h"
#include "Problem.h"

using namespace std;

class DyV {

 public:
  DyV(){}
  virtual ~DyV(){}
  Solution Solve(Problem data, int size) {
    if (Small(data)) {
      return SolveSmall(data);
    } else {
      cout << "Ey";
      vector<Problem> problems = Divide(data, size);
      Solution S1 = Solve(problems[0], size /2);
      Solution S2 = Solve(problems[1], size /2);
      Solution S = Combine(S1, S2);
      return S;
    }
  }

  virtual bool Small(Problem data) = 0;
  virtual Solution SolveSmall(Problem data) = 0;
  virtual std::vector<Problem> Divide(Problem data, int size) = 0;
  virtual Solution Combine(Solution data1, Solution data2) = 0;
};
#endif