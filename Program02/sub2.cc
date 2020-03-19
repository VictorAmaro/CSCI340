/************************************
Victor Amaro
CSCI 340
Due 9/08/16
Section 1
Program 2
implement two search algorithms (linear search and binary search) on randomly
generated integers stored in vectors
************************************/
#include "prog2.h"

/******************************
Function: Vectors()
Returns: Nothing
Arguments: A reference to a vector of integers called, vec1
	A reference to a vector of integers called, vec2
	A integer to hold seed value, seed1
	A integer to hold seed value, seed2
Purpose: Fills elements of vec1 and vec2 with random numbers
*******************************/
void Vectors(vector <int>& vec1, vector <int>& vec2, int seed1, int seed2) {
	srand(seed1); //fills vectors with random numbers
	for (int i = 0; i != ARR_SIZE; i++)
		vec1.at(i) = rand() % (HIGHEST_NUM - LOWEST_NUM + 1) + LOWEST_NUM;

	srand(seed2);
	for (int i = 0; i != TEST_ARR_SIZE; i++)
		vec2.at(i) = rand() % (HIGHEST_NUM - LOWEST_NUM + 1) + LOWEST_NUM;
}

/******************************
Function: linearSearch()
Returns: True, if item was found
	False, if item was not found
Arguments: A reference to a constant vector of integers, vec
	A integer to be searched for, itemSearch
Purpose: Linear Search, searches for the integer held in item search in the vector.
	Starts from beginning and stops when a match in found.
******************************/
bool linearSearch(const vector <int>& vec, int itemSearch) {
	//return find(vec.begin(), vec.end(), itemSearch) != vec.end(); //returns the true of false, if the number was found or not
	vector<int>::const_iterator vecIt; //iterator

	for (vecIt = vec.begin(); vecIt != vec.end(); vecIt++) { //cycle from start to end of vector
		if (itemSearch == *vecIt) //returns the true of false, if the number was found or not
			return true;
	}
	return false;
}

/******************************
Function: binarySearch()
Returns: True, if item was found
	False, if item was not found
Arguments: A rerference to a constant vector of integers, vec
	A integer to be searched for, itemSearch
Purpose: Binary Search, searches for the integer held in itemSearch in the vector
*******************************/
bool binarySearch(const vector <int>& vec, int itemSearch) {
	//return binary_search(vec.begin(), vec.end(), itemSearch);

	size_t mid, 
		left = 0,
		right = vec.size(); // one position passed the right end

	while (left < right) {
		mid = left + (right - left) / 2;
		if (itemSearch > vec[mid]) { //returns the true if number was found
			left = mid + 1;
		}
		else if (itemSearch < vec[mid]) {
			right = mid;
		}
		else {
			return true;
		}
	}
	return false;	//not found
}

/******************************
Function: search()
Returns: A integer that holds the total number of
	successful searches and returns that value
Arguments: A reference to a constant vector of integers called, vec1
	A reference to a constant vector of integers called, vec2
Purpose:computes the total number of successful searches
	and returns that value
*******************************/
int search(const vector <int>& vec1, const vector <int>& vec2, bool(*p)(const vector <int>&, int)) {
	vector<int>::const_iterator vecIt; //iterator
	int succCnt = 0; //successful count

	for (vecIt = vec2.begin(); vecIt != vec2.end(); vecIt++) {
		if (p(vec1, *vecIt)) //passes vector one (numbers to be searched through), and dereferenced iterator of vector two (item to be searched for)
			succCnt++;
	}

	return succCnt;
}

/*******************************
Function: sort()
Returns: Nothing
Arguments: A referance to a vector of integers, vec
Purpose: Sorts the vector in ascending order
********************************/
void sortVector(vector <int>& vec) {
	//sort(vec.begin(), vec.end());
	int i = 0,
		j = 0,
		temp = 0;

	for (i = 1; i < vec.size(); i++) { //insertion sort
		j = i;
		temp = vec[i];

		while (j > 0 && temp < vec[j - 1]) {
			vec[j] = vec[j - 1];
			j--;
		}
		vec[j] = temp;
	}
}

/*******************************
Function: printVector()
Returns: Nothing
Arguments: A reference to a vector of integers, vec
Purpose: Prints the the vector
********************************/
void printVector(const vector <int>& vec) {
	vector<int>::const_iterator vecIt;
	int itemCnt = 0;

	for (vecIt = vec.begin(); vecIt != vec.end(); vecIt++) {
		if (itemCnt % PER_LINE == 0 && itemCnt != 0) //makes a new line if desired numbers of items per line is reached
			cout << endl;
		cout << fixed << right << setw(ITEM_WIDTH) << *vecIt;
		itemCnt++;
	}
	cout << endl;
}

/********************************
Function: printStat()
Returns: Nothing
Arguments: A integer that holds sie of vector, vectorSz
	A integer that holds number of successful comparisons, totalSucCnt
Purpose: Prints percent of successful searches
*********************************/
void printStat(int totalSucCnt, int vectorSz) {
	cout << setprecision(2) << "     Percent of Successful Searches = " << ((double)totalSucCnt / vectorSz) * 100 << "%" << endl;
}
