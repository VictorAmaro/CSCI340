/*
Victor Amaro
Section 1
Prog7
implement a derived class (as a template) to represent a binary search tree
*/
#ifndef BINSTREE_H
#define BINSTREE_H

#include <vector>
#include <algorithm>
using std::generate; using std::sort;

#include "binTree.h"

template <class T> //foward declartion
class binSTree;

template < class T >
class binSTree : public binTree <T> {
    public:
    void insert ( const T& ); // public insert()
    void remove ( const T& ); // public remove()

    private:
    void insert ( Node < T >*&, const T& ); // private version of insert
    void remove ( Node < T >*&, const T& ); // private version of remove
    Node<T>* pred ( Node<T>* ); // returns predecessor of node
};

/*
   ==== Public Version====
insert(const T&)
returns: nothing
purpose: calls the private version of insert() and passes the root along
    with the item to be inserted
arguments: a constant reference to a class T object, called element, which
    is the item to be inserted
*/
template <class T>
void binSTree<T>::insert( const T& element ) {
    insert(this->root, element);
}

/*
   ==== Public Version ====
remove(const T&)
returns: nothing
purpose: calls the private version of remove() and passes the root along
    with the item to be deleted
arguments: a constant reference to a class T object, called element, which
    is the item to be deleted
*/
template <class T>
void binSTree<T>::remove( const T& element ) {
    remove(this->root, element);
}


/*
   ==== Private Version ====
insert(const T&)
returns: nothing
purpose: Inserts a element in the tree
arguments: A reference to a Node pointer of class T, ptr - holds the root
    A constant reference to a class T object, element - item to be inserted
*/
template <class T>
void binSTree<T>::insert( Node<T>*& ptr, const T& element ) {
    if(ptr == NULL)
        ptr = new Node<T>(element);
    else {
        if(element < ptr->data)	//trying to insert something smaller than the Node, go to left
            insert(ptr->left, element);
        else
            insert(ptr->right, element);
    }
}

/*
  ==== Private Version ====
remove(Node*&, const T&)
returns: nothing
purpose: removes the desired element from the tree
arguments: A reference to a class T object, element - item to be deleted
    A reference to a Node pointer of class T, ptr - holds the root
*/
template <class T>
void binSTree<T>::remove( Node<T>*& ptr, const T& element ) {
    Node<T>* temp = ptr;

    if(ptr == NULL)
        return ; //node doesnt exist
    else if(element < ptr->data)	//if the desired element is smaller than node, location is to the left
        remove(ptr->left, element);
    else if(element > ptr->data)
        remove(ptr->right, element);
    else {	//we have reached element to delete
        //no Child
        if(ptr->left == NULL && ptr->right == NULL){
			delete ptr;
            ptr = NULL;
        }
        //one child
        else if( ptr->right == NULL) {
            ptr = ptr->left;
            delete temp;
        }
        else if( ptr->left == NULL) {
            ptr = ptr->right;
            delete temp;
        }
        //two childs
        else {
            temp = pred(ptr->left);
            ptr->data = temp->data;
            remove(ptr->left, temp->data);
        }
    }
}

/*
pred(Node<T>*
returns: A pointer to a class T Node, the predecessor of a node
arguments: A pointer to a class T Node, called ptr
purpose: Finds the predecessor of the node
*/
template <class T>
Node<T>* binSTree<T>::pred( Node<T>* ptr) {
    while(ptr->right != NULL) {
        ptr = ptr->right;
    }
    return ptr;
}

#endif