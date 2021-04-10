/*-- BSTArray.h ---------------------------------------------------------------

  This header file defines the class for a Binary Search Tree using and array
  Basic operations are:
	 Constructor
	 Destructor
	 search:		Search for given data and print search path
	 findMin:	Print the Minimum value of the tree
	 findMax:	Print the Maximum value of the tree
	 print:		Print the tree in linear order with index values
	 insert:		Insert value at appropriate location
  @author Ross Adams
-----------------------------------------------------------------------------*/
#pragma once
#ifndef BSTARRAY_H
#define BSTARRAY_H
#include "ElementType.h"
// Create BSTArray class defintiion here
// Remember, your underlying data type will be an array, not a linked list!
// Don't forget class definitions end with a semi-colon!
class BSTArray {
private:
	const int CAPACITY = 256; // Maximum capacity required for array
	ElementType* array;  // Array pointer

public:
	/* Constructor */
	BSTArray();
	
	/* Destructor */
	~BSTArray();

	/* Find and return the index that stores the given data value using
	vinary search tree mechanism. Also prints the elements in the search
	path.*/
	int search(ElementType data);
	
	/* Find and print the maximum value in the BST. */
	void findMax();
	
	/* Find and print the minimum value in the BST. */
	void findMin();
	
	/* Print out the BST structure in the form of and array with the
	corresponding index*/
	void print();
	
	/* Insert a value element into the array */
	void insert(ElementType data);
};

#endif