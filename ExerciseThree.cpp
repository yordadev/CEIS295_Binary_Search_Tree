/********************************************
*   implementation of a binary search tree  *
*********************************************/

#include <iostream>
#include "SimpleBag.h"
#include <sstream>
#include <time.h>

using namespace std;

int main()
{
	SimpleBag integerBag;
	SimpleBag secondIntegerBag;


	int x;

	srand((unsigned int)time(0));

	
	for (int i = 0; i < 10; i++) {
		x = rand() % 20;
		integerBag.add(x);
		secondIntegerBag.add(x);
	}
		

	if (!integerBag.isEmpty()) {
		cout << "The bag contains: " << endl;
		integerBag.print();
	} else {
		cout << "The bag is empty." << endl;
	}

	string foundString;
	stringstream convertToString;
	convertToString << integerBag.count(x);
	foundString = convertToString.str();

	cout << "There are: " << foundString << " occurences of " << x << " in the simple bag." << endl;
	

	integerBag.~SimpleBag();

	secondIntegerBag.clear();
	
	
	return 0;
}