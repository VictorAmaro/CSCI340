#pragma once
#ifndef PROG1_H 
#define PROG1_H

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using std::cout; using std::endl;
using std::setw; using std::left; using std::fixed;
using std::vector; using std::sort;

const int VEC_SIZE = 250; //Max vector size
const int VEC_LOW = 1; //Lowest possible number
const int VEC_HIGH = 10000; //Highest possible numbers
const int NUMBER_OF_ITEMS = 12; //Max items per line when displaying
const int ITEM_WIDTH = 5; //The width between items when displaying

void genRandNums(vector <int>& vecList);
void printVec(const vector <int>& vecList);
void sortVec(vector <int>& vecList);

#endif