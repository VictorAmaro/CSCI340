#ifndef PROG3_H
#define PROG3_H

#include <iostream>
#include <iomanip>
#include <set>

using std::cout; using std::endl; using std::cin;
using std::setw; using std::right; using std::fixed;
using std::set;

const int ITEM_WIDTH = 4; //Width between items
const int NUM_PER_LINE = 20; //Items per line

void fillSet(set <int>& sieveSet, int upperLimit);
void sieve(set <int>& sieveSet ,int upperLimit);
void print_primes(const set <int>& sieveSet);
 
#endif