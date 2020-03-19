/*************************************
Victor Amaro
CSCI 340
Due August 30
Section 1
Program 1
generate random integers in a vector, then sort them in ascending order, and print them out
**************************************/
#include "prog1.h"

int main() {
	vector<int> vectorList; //Creates vector of integers
	genRandNums(vectorList); //fills vector with numbers
	//sort(vectorList.begin(), vectorList.end()); //sorts the vector
	sortVec(vectorList);
	printVec(vectorList); //prints vector

	return 0;
}

/***************************************
Function: genRandNums()
Returns: Nothing
Arguments: A reference to a vector of
	integers called, vecList
Purpose: Seeds the RNG,
	Will fill the vector with numbers,
	Will sort vector from lowest to highest
****************************************/
void genRandNums(vector <int>& vecList) {
	srand(1);

	for (int i = 0; i != VEC_SIZE; i++) {
		int randNum = rand() % (VEC_HIGH - VEC_LOW + 1) + VEC_LOW;
		vecList.push_back(randNum);
	}
}

/***************************************
Function: sortVec()
Returns: Nothing
Arguments: A reference to a vector of
	integers called, vecList
Purpose: sort vector in ascending order
****************************************/
void sortVec(vector <int>& vecList) {
	int i = 0,
		j = 0,
		temp = 0;

	for (i = 1; i < VEC_SIZE; i++) {
		j = i;
		temp = vecList[i];

		while (j > 0 && temp < vecList[j - 1]) {
			vecList[j] = vecList[j - 1];
			j--;
		}
		vecList[j] = temp;
	}
}

/***************************************
Function: printVec()
Returns: Nothing
Arugments: A reference to a constant vector
		of integers called, vecList
Purpose: Displays the items in the vector
		with the specified width and items per line
****************************************/
void printVec(const vector <int>& vecList) {
	vector<int>::const_iterator vecIt;
	int itemCount = 0;

	for (vecIt = vecList.begin(); vecIt != vecList.end(); vecIt++) {
		if (itemCount % NUMBER_OF_ITEMS == 0 && itemCount != 0)
			cout << endl;
		cout << fixed << left << setw(ITEM_WIDTH) << *vecIt;
		itemCount++;
	}
	cout << endl;
}