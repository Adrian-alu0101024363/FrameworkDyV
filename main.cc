#include "DyV.h"
#include <iostream>
#include <vector>
#include "MergeSort.h"

int main(void) {
  std::vector<int> data = {2, 1, 3, 6};
  //DyV<std::vector<int>>* dyv = new MergeSort<std::vector<int>>;
  MergeSort<std::vector<int>> dyv;
  std::vector<int> sol = dyv.Solve(data, 0 , data.size() - 1);
  std::cout << std::endl << "Size de sol: " << sol.size();
  for (int i = 0; i < sol.size(); i++) {
    std::cout << sol[i];
  }
}