#include "DyV.h"
#include <iostream>
#include <vector>
#include "MergeSort.h"
#include "Vector.h"
#include "Vectorf.h"
#include "Vectorbinary.h"
#include "QuickSort.h"
#include "binary.h"
#include <string>

using namespace std;

int main(int argc,char* argv[]) {
  string action;
  int choice = 0;
  std::vector<float> data = {4,2,1,3,6,7,5};
  std::vector<float> data2 = {1,2,3,4,5,6,7,8};
  std::vector<float> data3 = {1,2,3,4,5,6,7};
  cout << "Original vector: " << endl;
  for (int i = 0; i < data.size(); i++) {
    std::cout << data[i] << ',';
  }
  if (argc == 2) {
    action = argv[1];
    if (action == "debug") {
      cout << "debug";
    }
    cout << endl << "Choose Algorithm: 1-Merge 2-Quick 3-Binary" << endl;
    cin >> choice;
    if (choice == 1) {
      Vectorf p(data);
      DyV<Vectorf,Vectorf>* dyv = new MergeSort<Vectorf,Vectorf>;
      Vectorf sol = dyv->Solve(p, p.size() - 1);
      cout << "Solution vector: " << endl;
      for (int i = 0; i < sol.size(); i++) {
        std::cout << sol[i] << ',';
      }  
      dyv->info();    
    } else if (choice == 2) {
      Vectorf p(data);
      DyV<Vectorf,Vectorf>* dyv = new Quicksort<Vectorf,Vectorf>;
      Vectorf sol = dyv->Solve(p, p.size() - 1);
      cout << "Solution vector: " << endl;
      for (int i = 0; i < sol.size(); i++) {
        std::cout << sol[i] << ',';
      } 
      dyv->info(); 
    } else if (choice == 3) {
      Vectorbinary p(data2);
      p.setValue(2);
      DyV<Vectorbinary,Vectorbinary>* dyv = new Binary<Vectorbinary,Vectorbinary>;
      Vectorbinary sol = dyv->Solve(p, p.size() - 1); 
      dyv->info();
      cout << endl << "Encontrado?: " << sol.getFounded() << endl;
    } else {
      cout << "Incorrect option";
    }
  } else {
    cout << "Incorrect format" << endl;
  }
  /*
  //std::vector<int> data = {2, 1, 6, 3, 8, 5, 12, 14};
  //std::vector<float> data = {2.2, 2.1, 6, 3, 8, 5, 7, 4, 9};
  std::vector<float> data = {1,2,3,4,5,6,7};
  //std::vector<float> data = {2.2, 2.1, 6, 3};
  cout << "Original vector: " << endl;
  for (int i = 0; i < data.size(); i++) {
    std::cout << data[i] << ',';
  }
  //Vectorf p(data);
  Vectorbinary p(data);
  p.setValue(3);
  //DyV<Problem,Solution>* dyv = new MergeSort<Problem,Solution>;
  //MergeSort<Vectorf,Vectorf> dyv;
  //Quicksort<Vectorf,Vectorf> dyv;
  DyV<Vectorbinary,Vectorbinary>* dyv = new Binary<Vectorbinary,Vectorbinary>;
  //Binary<Vectorbinary,Vectorbinary> dyv;
  Vectorbinary sol = dyv->Solve(p, p.size() - 1);
  std::cout << std::endl << "Solution size: " << sol.size() << endl;
  cout << "Solution vector: " << endl;
  for (int i = 0; i < sol.size(); i++) {
    std::cout << sol[i] << ',';
  }
  cout << endl << "Encontrado?: " << sol.getFounded() << endl;
  dyv->info();
  */
}