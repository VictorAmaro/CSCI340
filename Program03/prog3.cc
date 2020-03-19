/*************************************************
Victor Amaro
CSCI 340
Due Sept 16 2016
Section 1
Program 3
interactive C++ program to find and print all prime numbers, which are less than or equal to a given
value of n, using the algorithm known as the Sieve of Eratosthenes
************************************************/
#include "prog3.h"

int main() {
	int upperLimit;

	cout << "Upper limit for the set of primes: "; //asks user to enter the upper limit for the set
	cin >> upperLimit;
	cout << endl;

	set <int> sieveSet;

	fillSet(sieveSet, upperLimit); //fills set
	sieve(sieveSet, upperLimit);
	print_primes(sieveSet); //prints set

	return 0;
}

/************************************
Function: filSet()
Returns: Nothing
Arguments: A reference to a set of integers, sieveSet
	A integer that holds the upper limit of the set, upperLimit
Purpose: Fills the set starting from 2 all the way to the upper limit
************************************/
void fillSet(set <int>& sieveSet, int upperLimit) {
	for (int i = 2; i <= upperLimit; i++)
		sieveSet.insert(i);
}

/************************************
Function: sieve()
Returns: Nothing
Arguments: A reference to a set of integers, sieveSet
	A integer that holds the upper limit of the set, upperLimit
Purpose: Applies the Sieve of Eratosthenes algorithm to
	remove all non prime numbers from the set.
************************************/
void sieve(set <int>& sieveSet, int upperLimit) {
	set <int>::const_iterator setIt; //iterator

	for (int j = 2; j * j <= upperLimit; j++) { //runs until the upper limit is reached
		for (setIt = sieveSet.begin(); setIt != sieveSet.end(); setIt++) { //cycle through vector
			if (j == *setIt) { //did we find a non prime number (j) within the vector (setIt)?
				int i = 0;
				i = 2 * j;
				while (i <= upperLimit) { //remove all the non prime inbetween
					sieveSet.erase(i);
					i += j;
				}
			}
		}
	}
}

/************************************
Function: print_primes()
Returns: Nothing
Arguments: A constant reference to a set of integers, sieveSet
Purpose: Prints out the set, with desired width and items per line
************************************/
void print_primes(const set <int>& sieveSet) {
	set <int>::const_iterator setIt; //iterator
	int itemCount = 0; //count for items

	for (setIt = sieveSet.begin(); setIt != sieveSet.end(); setIt++) {
		if (itemCount % NUM_PER_LINE == 0 && itemCount != 0) //makes a new line once desired  amount is reached
			cout << endl;
		cout << fixed << right << setw(ITEM_WIDTH) << *setIt << " "; //prints out current element and sets width
		itemCount++;
	}
	cout << endl;
}