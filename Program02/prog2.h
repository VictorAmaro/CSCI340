#ifndef PROG2_H
#define PROG2_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>

using std::cout; using std::endl;
using std::setw; using std::right; using std::setprecision; using std::fixed;
using std::vector; using std::sort;
using std::find; using std::binary_search;

const int LOWEST_NUM = 1; //lowest number possible
const int HIGHEST_NUM = 1000; //highest number possible
const int ITEM_WIDTH = 5;
const int PER_LINE = 16;
const int ARR_SIZE = 200; //size of array with number to search through
const int TEST_ARR_SIZE = 100; //size of array filled with numbers to be searched for
const int SEED1 = 1;
const int SEED2 = 3;

//function prototypes
void Vectors(vector <int>& vec1, vector <int>& vec2, int seed1, int seed2);
bool linearSearch(const vector <int>& vec, int itemSearch);
bool binarySearch(const vector <int>& vec,const int itemSearch);
int search(const vector <int>& vec1, const vector <int>& vec2, bool(*p)(const vector <int>&, int));
void sortVector(vector <int>& vec);
void printVector(const vector <int>& vec);
void printStat(int totalSucCnt, int vectorSz);
  
#endif
