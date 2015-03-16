#pragma once
#include <iostream>
#include <stack>
#include "Node.h"

using namespace std;

class Tree
{
private:
	Node* root;
	int value;
	stack<Node*> s;
public:
	Tree();
	void traverse();
	void traverseRecursive();
	void traverseRecursiveHelper(Node*);
	void insert(int);
	Node* insertHelper(Node*, int);
	void balance(Node*);
	void placeNode(Node*);
	void setHeight(Node*);
	int setHeightHelperLeft(Node*);
	int setHeightHelperRight(Node*);
	Node* rotateLeft(Node*);
	Node* rotateRight(Node*);
	int balanceTree(Node*);
	int treeHeight(Node*);
	void deleteTree(Node*);
	~Tree();
};