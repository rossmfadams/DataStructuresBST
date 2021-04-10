/*-- BSTArray.cpp--------------------------------------------------------------
   This file implements the BSTArray member functions.
   @author Ross Adams
-----------------------------------------------------------------------------*/
#include "BSTArray.h"
#include <iostream>

using namespace std;

/*---------------------------------------------------------------------------*/
 
BSTArray::BSTArray()
{
	// Declare variables and dynamically allocate memory for an array
	int i = 0;  // Counter
	array = new ElementType[CAPACITY]; // Dynamically allocated array

	// Initialize all values to -1
	for (i = 0; i < CAPACITY; i++) {
		array[i] = -1;
	}  // End for
}  // End constructor

/*---------------------------------------------------------------------------*/

BSTArray::~BSTArray()
{
	delete[] array;
}  // End destructor

/*---------------------------------------------------------------------------*/

int BSTArray::search(ElementType data)
{
	// Declare local variables
	int i = 1; // Root of the tree starts at index [1]
	int index = -1;  // Return value
	int child = 1;  // Used for traversing the tree

	// Check if empty tree
	if (array[child] == -1) {
		cout << "Empty array. Cannot be searched." << endl;
	} // end if
	else {
		// Compare data to root
		if (array[child] == data) {
			index = 1;
		} // end if
		else {
			// Traverse through the tree
			while (array[child] != -1 && array[index] != data) {
				// Go left
				index = child;
				if (data < array[index]) {
					// Print search path
					cout << data << " < [" << index << "]:" << array[index]
						<< endl;
					index = child;
					child = (2 * child);
				}  // End if

				// Go right
				else {
					index = child;

					// Print either =/> based on comparison
					if (array[index] == data) {
						cout << data << " = [" << index << "]:" << array[index]
							<< endl;
					}  // End if
					else {
						cout << data << " > [" << index << "]:" << array[index]
							<< endl;
					} // End else
					child = (2 * child) + 1;
				}  // End else

				// Traversal complete and data not found in tree
				if (array[child] == -1 && array[index] != data) {
					index = -1;
					cout << "Element " << data << " not found." << endl;
				}  // End if
			}  // End while
		}  // End else
	} // End else
	return index;
}  // End search

/*---------------------------------------------------------------------------*/

void BSTArray::findMax()
{
	// Declare local variable
	int index = 1;  // Used for traversing the tree
	ElementType max = array[index];  // Holds maximum value

	// Traverse all the way to the right
	while (array[index] != -1) {
		max = array[index];
		
		// For any node, the right child can be found at (2 * index) + 1
		index = (2 * index) + 1;
	}  // End while
	
	// Check if empty tree
	if (max == -1) {
		cout << "Empty array. No maximum." << endl;
	}  // End if
	else {
		cout << "Max: " << max << endl;
	}  // End else
}  // End findMax

/*---------------------------------------------------------------------------*/

void BSTArray::findMin()
{
	// Declare local variables
	int index = 1;  // Used for traversing the tree
	ElementType min = array[index];  // Holds minimum value

	// Traverse all the way to the left
	while (array[index] != -1) {
		min = array[index];
		
		// For any node, the left child can be found at index * 2
		index = (2 * index);
	}  // End while
	
	// Check if empty tree
	if (min == -1) {
		cout << "Empty array. No minimum." << endl;
	}  // End if
	else {
		cout << "Min: " << min << endl;
	}  // End else
}  // End findMin

/*---------------------------------------------------------------------------*/

void BSTArray::print()
{
	// Declare local variables
	int i = 0;  // Counter

	// Linear traversal
	for (i = 1; i < CAPACITY; i++) {
		
		// Print all non-empty values, paired with the corresponding index
		if (array[i] != -1) {
			cout << "[" << i << "]" << ":" << array[i] << " ";
			//cout << "(" << array[i] << "," << i << ") ";
		}  // End if
	}  // End for
	// Extra line
	cout << endl;
}  // End print

/*---------------------------------------------------------------------------*/

void BSTArray::insert(ElementType data)
{
	// Declare local variables
	int root = 1;  // Index of the tree's root
	int index = -1;  // Used for traversing the tree

	// Check if empty tree
	if (array[root] == -1) {
		array[root] = data;
	}  // End if
	else {
		index = root;

		// Traverse the tree looking for the insertion point
		while ((array[index] != -1) && (array[index] != data)) {
			// Go left
			if (data < array[index]) {
				index = (2 * index);
			}  // End if
			// Go right
			else {
				index = (2 * index) + 1;
			}  // End else
		}  // End while
		
		// Traversal finished and insertion point found
		if (array[index] == -1) {
			array[index] = data;
		}  // End if
		// Data already exists in tree. No duplicates allowed.
		else {
			cout << "Error! Node duplicate." << endl;
		}  // End else
	}  // End else
}  // End insert

/*---------------------------------------------------------------------------*/