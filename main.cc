#include "DyV.h"
#include <iostream>
#include <vector>
#include "MergeSort.h"
#include "Vector.h"
#include "Vectorf.h"
#include "QuickSort.h"

using namespace std;

int main(void) {
  //std::vector<int> data = {2, 1, 6, 3, 8, 5, 12, 14};
  std::vector<float> data = {2.2, 2.1, 6, 3, 8, 5, 7, 4, 9};
  //std::vector<float> data = {2.2, 2.1, 6, 3};
  cout << "Original vector: " << endl;
  for (int i = 0; i < data.size(); i++) {
    std::cout << data[i] << ',';
  }
  //Problem* p = new Vector(data);
  Vectorf p(data);
  //DyV<Problem,Solution>* dyv = new MergeSort<Problem,Solution>;
  //MergeSort<Vectorf,Vectorf> dyv;
  Quicksort<Vectorf,Vectorf> dyv;
  Vectorf sol = dyv.Solve(p, p.size() - 1);
  std::cout << std::endl << "Solution size: " << sol.size() << endl;
  cout << "Solution vector: " << endl;
  for (int i = 0; i < sol.size(); i++) {
    std::cout << sol[i] << ',';
  }
}