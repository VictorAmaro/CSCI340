/*
Victor Amaro
Section 1
Prog 6
a C++ program to implement a class for binary trees.
To deal with variety of data types, implement this class as a template.
*/
#ifndef BINTREE_H
#define BINTREE_H

//include "/home/cs340/progs/16f/p7/Node.h"
#include "Node.h"

template <class T> //foward declartion of binTree class
class binTree;

template <class T>
class binTree {
    public:
    binTree() { root = NULL; };              //default constructor, sets root to NULL
    unsigned height () const;               //public height()
    virtual void insert( const T& );        //public insert()
    void inorder( void (*) (const T&) );    //public inorder()
    unsigned size() const;                  //public size()

    typedef enum { left_side, right_side } SIDE;
    SIDE rnd ( ) { return rand ( ) % 2 ? right_side : left_side; } //Used to decide random placement of Nodes, either left or right side
                                    //If the number is even, right side - else left side
    protected:
    Node <T>* root; //root of tree

    private:
    unsigned height( Node<T>* ) const;              //private height()
    void insert( Node<T>*&, const T& );             //private insert()
    void inorder( Node<T>*, void (*) (const T&) );  //private inorder()
    unsigned size( Node<T>* ) const;                //private version size()
};

/*
===Public Version===
size() const
returns: an unsigned int, the size of the tree
arguments: none
purpose: calls the private version of height
*/
template <class T>
unsigned binTree<T>::size() const {
    return size(root);
}

/*
===Public version===
height() const
returns: The height of the tree
arguments: none
purpose: calls the private version of height()
*/
template <class T>
unsigned binTree<T>::height() const {
    return height(root);
}

/*
===Public version===
inorder()
returns: nothing
arguments: A pointer to a function that takes a class T element
Purpose: Calls the private version of inorder()
*/
template <class T>
void binTree<T>::inorder( void (*func) (const T& ) ) {
    inorder(root, func );
}

/*
===Public version===
insert()
returns: nothing
arugments: a reference to a constant class T, called element
Purpose: calls the private version of insert()
*/
template <class T>
void binTree<T>::insert( const T& element ) {
    insert(root, element);
}


/*
==Private Version==
returns: an unisgned int, the size of the tree
arguments: A pointer to a class T Node (in this case, root)
purpose: finds the size of the tree
*/
template <class T>
unsigned binTree<T>:: size( Node<T>* ptr ) const {
    if(ptr == NULL) //if null, size = 0
        return 0;
    else
        return (size(ptr->left) + 1 + size(ptr->right));
}

/*
===Private version===
height() const
arguments: a pointer to a Node of class T, called ptr (holds the root)
returns: the height of the tree
purpose: finds the height of the tree,
    if there are no Nodes, returns a height of 0
*/
template <class T>
unsigned binTree<T>::height( Node<T>* ptr) const {
    if(!ptr) //if null, height = 0
        return 0;
	else {
		int left = height(ptr->left),
			right = height(ptr->right);

		return (left > right ? left + 1 : right + 1); //return the greater of sides
	}
}

/*
===Private version===
insert()
returns: nothing
arguments: A pointer to a reference Node of class T, called ptr (holds the root)
    A constant reference to a class T, called element (element to be inserted)
purpose: Adds an item to the tree,
    If there is no Node, creates a new one, sets necessary pointers to NULL and sets Node data to the element.
    Decides where to make the new Node based on rnd() method call
*/
template <class T>
void binTree<T>::insert( Node<T>*& ptr, const T& element) {
    if(ptr == NULL) {
        ptr = new Node<T>();
        ptr->right = NULL;
        ptr->left = NULL;
        ptr->data = element;
    }
    else if( rnd() == right_side ) //if rnd == right_side, make new node on right
        insert(ptr->right, element);
    else //else left
        insert(ptr->left, element);
}

/*
===Private version===
inorder()
returns: nothing
arguments: a pointer to a Node of class T, called ptr (holds root).
    A pointer function that takes a class T argument
Purpose: Goes through the tree using in order method, using recursion
*/
template <class T>
void binTree<T>::inorder( Node<T>* ptr, void (*func) (const T& ) ) {
    if(ptr != NULL) {
        inorder(ptr->left,func );
        func( ptr->data );
        inorder(ptr->right, func);
    }
}
#endif
