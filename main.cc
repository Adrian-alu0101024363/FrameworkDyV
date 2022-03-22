#include "DyV.h"
#include <iostream>
#include <vector>
#include "MergeSort.h"
#include "Solution.h"
#include "Problem.h"

using namespace std;

int main(void) {
  std::vector<int> data = {2, 1, 6, 3, 8, 5, 12, 14, 4};
  cout << "Original vector: " << endl;
  for (int i = 0; i < data.size(); i++) {
    std::cout << data[i] << ',';
  }
  Problem p(data);
  //DyV<std::vector<int>>* dyv = new MergeSort<std::vector<int>>;
  MergeSort<Problem,Solution> dyv;
  Solution sol = dyv.Solve(p, p.size() - 1);
  std::cout << std::endl << "Solution size: " << sol.size() << endl;
  cout << "Solution vector: " << endl;
  for (int i = 0; i < sol.size(); i++) {
    std::cout << sol[i] << ',';
  }
}