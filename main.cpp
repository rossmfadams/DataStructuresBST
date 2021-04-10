/*-- main.cpp------------------------------------------------------------------
   This file implements the driver for the BSTArray
   @author Ross Adams
-----------------------------------------------------------------------------*/
#include "BSTArray.h"

#include <iostream>
using namespace std;

/*---------------------------------------------------------------------------*/

int main()
{
	// Declare/Instantiate variable
	int index = 0;

	// Create object pointer
	BSTArray* tree = new BSTArray();

	// Call methods on object
	tree->insert(5);
	tree->insert(8);
	tree->insert(3);
	tree->insert(1);
	tree->insert(4);
	tree->insert(9);
	tree->insert(18);
	tree->insert(20);
	tree->insert(19);
	tree->insert(2);
	tree->print();
	tree->findMax();
	tree->findMin();
	index = tree->search(3);
	cout << "The index of 3 is: " << index << endl;
	index = tree->search(18);
	cout << "The index of 18 is: " << index << endl;
	index = tree->search(19);
	cout << "The index of 19 is: " << index << endl;
	tree->search(7);
	// Destroy object
	delete tree;

}  // End main

