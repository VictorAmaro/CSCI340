/*
Victor Amaro
Section 1
Program 9
Program to create, search, print, and sort an item inventory.
The item inventory information will be kept in a sequentially allocated table with a given size of entries.
*/

//#include "/home/cs340/progs/16f/p9/hTable.h"
#include "hTable.h"

/*
compare class
Used in the insertion method, to compare if the key already exsits or not
*/
class compare {
    public:
    compare(const string& x):val(x){}

    bool operator()(const Entry& e) {
            return val == e.key;
    }

    private:
    string val;
};

/*
Destructor
Use: frees the memory for the vector containers for the hash table and the pointer table
*/
HT::~HT() {
    for (unsigned i = 0; i < hsize; i++)
                    hTable.pop_back();

    for (unsigned i = 0; i < pTable.size(); i++)
                    delete pTable[i];
}

/*
Constructor
Use: resizes the hash table and sets hsize
*/
HT::HT(const unsigned& hs) {
    hsize = hs;
    hTable.resize(hsize);
}

/*
inser()
returns: nothing
arguments: a constant reference to an Entry, called e,
    This is the desired entry to insert into table
purpose: finds a hash value for the desired Entry,
    tries to insert, if it already exsits, not places,
    else, it inserts the Entry in the hash table and the address of the Entry into the pointer table (pTable)
*/
void HT::insert(const Entry& e) {
    int hashVal = hash(e.key);
    hashVal %= hsize; //make sure its within size

    list <Entry>& lst = hTable[hashVal];

    if( find_if( lst.begin(), lst.end(), compare(e.key) ) != lst.cend() ) {
            cout << " That key already exists! Not inserted!" << endl;
            return; //key already is here, exit
        }
    else {
        lst.push_front(e);
        Entry *newEntry = new Entry(e.key,e.desc,e.num);
        pTable.push_back(newEntry);
        cout << " entry = " << hashVal  << endl;
    }
}

/*
search()
returns: nothing
arguments: a constant reference to a string, called key,
    the key to be looked for in hash table
purpose: searches the hash table for the given key,
    returns a error message if not found,
    returns the key, and item if found
*/
void HT::search(const string& key) {
    int hashVal = hash(key);
    hashVal %= hsize; //make sure its within size

    list <Entry>& lst = hTable[hashVal];

    auto result = find_if( lst.begin(), lst.end(), //look for key
        [key](Entry e) {
            return key == e.key;
        }
    );

    if(result != lst.end() )
        cout << " ==> number:     "  << result->key  << " - item: " << result->desc << endl;
    else
        cout << " Key not found! " << endl;
}

/*
hTable_print()
returns: nothing
aguments: none
purpose:  prints the subscript and the contents of all (and only) the active records in the hash table
*/
void HT::hTable_print() {
    Entry displayEntry;

    for(unsigned i = 0; i < hTable.size(); i++) { //loop through the vector
        list <Entry>& lst  = hTable[i];

        for(auto it = lst.begin(); it != lst.end(); it++) {
            displayEntry = *it;

            cout.flags(ios::right);
            cout << "   "  << i << ":  "  << displayEntry.key << " -  " << displayEntry.num << "   -  " << displayEntry.desc << endl;
        }
    }
    cout << endl;
}

/*
pTable_print()
returns: nothing
arguments: none
purpose: same as hTable, but sorted in key alphabetical order
*/
void HT::pTable_print() {
    sort( pTable.begin(), pTable.end(),
        []( Entry* p, Entry* q) {
                return p->key < q->key;
        }
    );

    cout.flags(ios::right);

    for(auto it = pTable.begin(); it != pTable.end(); it++)
            cout << setw(6) << (*it)->key << "  -  " << (*it)->num << "  -  " << (*it)->desc  << endl;
}