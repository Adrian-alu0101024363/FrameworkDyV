#include "DyV.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "algorithm/MergeSort.h"
#include "types/Vector.h"
#include "types/Vectorf.h"
#include "types/Vectorbinary.h"
#include "algorithm/QuickSort.h"
#include "algorithm/binary.h"
#include <string>
#include <ctime>
#include "Timer.h"
#include <fstream>

using namespace std;

/**
 * @brief Return n random instances of vectors with random values
 * 
 * @param n how many instances
 * @return vector<vector<int>> vector of random vectors
 */
vector<vector<int>> generate(int n) {
  vector<vector<int>> vec;
  for (int i = 0; i < n; i++) {
    int random = 1 + (rand() % 20);
    std::vector<int> vec2(random);
    for (int j = 0; j < vec2.size();j++) {
      int r = 1 + (rand() % 100);
      vec2[j] = r;
    }
    vec.push_back(vec2);
  }
  return vec;
}

/**
 * @brief Print a given vector to console
 * 
 * @param v vector to be printed
 */
void print(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << ',';
  }
}

/**
 * @brief Print to a given file a given vector with a different header
 * depending on m (1 for original, 2 for solution)
 * @param v vector to be printed
 * @param file file to print on
 * @param m mode 
 */
void printToFile(vector<int> v, string file, int m) {
  ofstream f;
  f.open(file,std::ios_base::app);
  f << endl;
  if (m == 1) {
    f << "Original vector: " << endl;
  }
  if (m == 2) {
    f << "Solution vector: " << endl;
  }
  for (int i = 0; i < v.size(); i++) {
    f << v[i] << ',';
  }
}

/**
 * @brief Given a vector of vectors solve each one with a quicksort using dyv
 * 
 * @param vectors vectors to be sorted
 * @param mode 1 for debug mode
 */
void solveQuick(vector<vector<int>> vectors, int mode) {
  ofstream f;
  f.open("output.txt",std::ios_base::app);
  for (vector<int> v : vectors) {
    Vector p(v);
    DyV<Vector,Vector>* dyv = new Quicksort<Vector,Vector>;
    Timer t;
    t.start();
    Vector sol = dyv->Solve(p, p.size() - 1);
    t.finish();
    string timeaux = "Time: " + to_string(t.getCpuTime()) + " Size: " + to_string(v.size()) + "\n";
    cout << timeaux;
    if (mode == 1) {
      f << "Quick" << endl;
      f << timeaux;
      cout << "Original vector: " << endl;
      for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ',';
      }
      cout << endl << "Solution vector: " << endl;
      for (int i = 0; i < sol.size(); i++) {
        std::cout << sol[i] << ',';
      }  
    }
    dyv->info(); 
    cout << endl;
  }
  f.close();
}

/**
 * @brief Given a vector of vectors solve each one with a merge using dyv
 * 
 * @param vectors vectors to be sorted
 * @param mode 1 for debug mode
 */
void solveMerge(vector<vector<int>> vectors, int mode) {
  ofstream f;
  f.open("output.txt",std::ios_base::app);
  for (vector<int> v : vectors) {
    Vector p(v);
    DyV<Vector,Vector>* dyv = new MergeSort<Vector,Vector>;
    Timer t;
    t.start();
    Vector sol = dyv->Solve(p, p.size() - 1);
    t.finish();
    string timeaux = "Time: " + to_string(t.getCpuTime()) + " Size: " + to_string(v.size()) + "\n";
    cout << timeaux;
    f << "MergeSort" << endl;
    f << timeaux;
    if (mode == 1) {
      cout << "Original vector: " << endl;
      print(v);
      //printToFile(v,"output.txt",1);
      cout << endl << "Solution vector: " << endl;
      print(sol.getVector());
      //printToFile(sol.getVector(),"output.txt",2);
    }
    dyv->info();
    cout << endl; 
  }
  f.close();
}

/**
 * @brief Given a vector of vectors solve each one with a binary search using dyv
 * 
 * @param vectors vectors to be sorted
 * @param mode 1 for debug mode
 */
void solveBinary(vector<vector<int>> vectors, int mode) {
  for (vector<int> v : vectors) {
    sort(v.begin(),v.end());
    Vectorbinary p(v);
    p.setValue(v[rand() % v.size()]);
    DyV<Vectorbinary,Vectorbinary>* dyv = new Binary<Vectorbinary,Vectorbinary>;
    Vectorbinary sol = dyv->Solve(p, p.size() - 1); 
    if (mode == 1) {
      cout << "Searching for: " << v[rand() % v.size()] << endl;
      cout << "Original vector: " << endl;
      for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ',';
      }
      cout << endl << "Found?: " << sol.getFounded() << endl;
    }
    dyv->info();
  }
}

// If the action given is 2 print to file a comparision of quick and merge sort
// If the action is 1 ask for the algorithm to execute and print the debug
// If the action is neither 1 or 2 print only the times of execution
int main(int argc,char* argv[]) {
  string action;
  int choice = 0;
  int n = 6;
  action = argv[1];
  if (argc == 2) {
    if (action == "2") {
      ofstream f;
      f.open("output.txt");
      vector<vector<int>> v = generate(n);
      cout << "Merge sort:" << endl;
      solveMerge(v,1);
      cout << "Quick sort: " << endl;
      solveQuick(v,1);
      f.close();
    } else {
      cout << endl << "Choose Algorithm: 1-Merge 2-Quick 3-Binary" << endl;
      cin >> choice;
      if (choice == 1) {
        solveMerge(generate(n),stoi(action));
      } else if (choice == 2) {
        solveQuick(generate(n),stoi(action));
      } else if (choice == 3) {
        solveBinary(generate(n),stoi(action));
      } else {
        cout << "Incorrect option";
      }
    }
  } else {
    cout << "Incorrect format" << endl;
  }
}