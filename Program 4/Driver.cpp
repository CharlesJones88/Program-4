//Name: Charles Jones
//CS2420 Section 002
//UV id: 10571948
//Program 4
//Date created: 9/25/2014
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include "Tree.h"

using namespace std;

int main()
{
	ifstream readCommand;
	string fileName;
	Tree myTree;
	int value;
	cout << "Charles Jones\nCS2420 Section 002\nProgram 4 - AVL Tree" << endl;
	cout << "Enter in a file name: ";
	cin >> fileName;
	try
	{
		readCommand.open(fileName);
		if (readCommand.fail())
			throw exception("file open exception");
	}
	catch (exception e)
	{
		cout << "A " << e.what() << " has occured. Terminating program." << endl;
		readCommand.close();
		system("pause");
		exit(EXIT_FAILURE);
	}
	while (readCommand >> value)
	{
		myTree.insert(value);
		readCommand.ignore();
	}
	myTree.traverse();
	myTree.traverseRecursive();
	readCommand.close();
	system("pause");
	return 0;
}