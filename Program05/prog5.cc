/*******************
Victor Amaro
prog 5
section 1
 C++ program to simulate and solve the Josephus problem
*******************/
#include <iostream>
#include <iomanip>
//#include "/home/cs340/progs/16f/p5/prog5.h"
#include "prog5.h"
using std::cout; using std::endl; using std::cin;
using std::advance;

const int TAGS_LINE = 12;

int main() {
    in_args josephusStruct; //creates a struct to hold values for Josephus Problem
    vector<string> josephusVec; //creates a vector to hold the names for Josephus Problem
    unsigned cnt = 1; //count of number of passes

    cout << "\nNumber of people? 41"; //Sets values to corresponding members of the struct
    josephusStruct.N = 41;
    cout << "\nIndex for emlination? 3";
    josephusStruct.M = 3;
    cout << "\nIndex for printing? 7 \n";
    josephusStruct.K = 7;

    init_vals(josephusVec, josephusStruct); //calles function to fill up vector
    print_vector(josephusVec, cnt); //prints the intital vector with all names before elimation begins

    josephusStruct.M -= 1; //adjusts elimation index
    auto indexIt = josephusStruct.M % josephusVec.size(); //iterator to be used for index elimation

    while(josephusVec.size() >1) { //runs until only one left in vector
        auto vecIter = josephusVec.begin(); //iterator for vector

		vecIter += indexIt; //advances Mth spot in the vector

        josephusVec.erase(vecIter); //deletes that element in the vector
        indexIt += josephusStruct.M; //adjuts iterator for index elimation
        indexIt %= josephusVec.size();

    if( (cnt % josephusStruct.K == 0 && cnt != 0) || josephusVec.size() == 1) //prints out vector with the header every Kth time
        print_vector(josephusVec, cnt);

    cnt++; //increment number of passes
    }

    cout << endl;
    return 0;
}

 
/**************************
Function: init_vals()
returns: nothing
arguments: A reference to a vector called vec
    A struct called in, holds values for the josephus problem
purpose: Resizes the vector to the value held in in.M
Fills the vector with the names A1,A2...B1 and so on.
***************************/
void init_vals(vector<string>& vec, in_args& in) {
    vec.resize(in.N);
    generate(vec.begin(), vec.end(), SEQ(in.N));
}

/**************************
Function: print_vector()
returns: nothing
Arguments: A reference to a constant vector called vec, holds the vector of people
    A constant unsiged variable called cnt, holds number of passes
Purpose: Prints out the vector elements with the correct header and items per line
**************************/
void print_vector(const vector<string>& vec, const unsigned& cnt) {
    vector<string>::const_iterator vecIt; //iterator to print items in vector
    int itemCnt = 0; //count for items per line

    if(cnt < 2) { //prints out the intial group header
        cout << "\n Initial group of people \n"
             << "-------------------------" << endl;
    }
    else { //prints out after elimation group header
        cout <<"\n After emliminating the " << cnt << "th person" << endl
             << "------------------------------------" << endl;
    }

    for(vecIt = vec.begin(); vecIt != vec.end(); vecIt++) { //for loop to iterate thrpugh items in vector and print them
        if(itemCnt % TAGS_LINE == 0 && itemCnt != 0) //prints a new line once desiered number of items per line is reached
            cout << endl;
    cout << *vecIt << " ";
        itemCnt++;
    } 
    cout << endl;
}