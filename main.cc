#include "DyV.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "MergeSort.h"
#include "Vector.h"
#include "Vectorf.h"
#include "Vectorbinary.h"
#include "QuickSort.h"
#include "binary.h"
#include <string>
#include <ctime>

using namespace std;

vector<vector<float>> generate() {
  vector<vector<float>> vec;
  for (int i = 0; i < 6; i++) {
    int random = 1 + (rand() % 20);
    std::vector<float> vec2(random);
    for (int j = 0; j < vec2.size();j++) {
      float r = 1 + (rand() % 100);
      vec2[j] = r;
    }
    vec.push_back(vec2);
  }
  return vec;
}

void solveQuick(vector<vector<float>> vectors) {
  for (vector<float> v : vectors) {
    Vectorf p(v);
    DyV<Vectorf,Vectorf>* dyv = new Quicksort<Vectorf,Vectorf>;
    Vectorf sol = dyv->Solve(p, p.size() - 1);
    cout << "Solution vector: " << endl;
    for (int i = 0; i < sol.size(); i++) {
      std::cout << sol[i] << ',';
    } 
    dyv->info(); 
  }
}

void solveMerge(vector<vector<float>> vectors) {
  for (vector<float> v : vectors) {
    cout << "Original vector: " << endl;
    for (int i = 0; i < v.size(); i++) {
      std::cout << v[i] << ',';
    }
    Vectorf p(v);
    DyV<Vectorf,Vectorf>* dyv = new MergeSort<Vectorf,Vectorf>;
    Vectorf sol = dyv->Solve(p, p.size() - 1);
    cout << "Solution vector: " << endl;
    for (int i = 0; i < sol.size(); i++) {
      std::cout << sol[i] << ',';
    }  
    dyv->info(); 
  }
}

void solveBinary(vector<vector<float>> vectors) {
  for (vector<float> v : vectors) {
    sort(v.begin(),v.end());
    cout << "Original vector: " << endl;
    for (int i = 0; i < v.size(); i++) {
      std::cout << v[i] << ',';
    }
    Vectorbinary p(v);
    p.setValue(v[rand() % v.size()]);
    cout << "Buscando: " << v[rand() % v.size()] << endl;
    DyV<Vectorbinary,Vectorbinary>* dyv = new Binary<Vectorbinary,Vectorbinary>;
    Vectorbinary sol = dyv->Solve(p, p.size() - 1); 
    dyv->info();
    cout << endl << "Encontrado?: " << sol.getFounded() << endl;
  }
}

int main(int argc,char* argv[]) {
  string action;
  int choice = 0;
  std::vector<float> data = {4,2,1,3,6,7,5};
  std::vector<float> data2 = {1,2,3,4,5,6,7,8};
  if (argc == 2) {
    action = argv[1];
    if (action == "debug") {
      cout << "debug";
    }
    cout << endl << "Choose Algorithm: 1-Merge 2-Quick 3-Binary" << endl;
    cin >> choice;
    if (choice == 1) {
      solveMerge(generate());
    } else if (choice == 2) {
      solveQuick(generate());
    } else if (choice == 3) {
      solveBinary(generate());
    } else {
      cout << "Incorrect option";
    }
  } else {
    cout << "Incorrect format" << endl;
  }
}