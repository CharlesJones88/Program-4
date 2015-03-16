#pragma once
class Node
{
private:
	int value;
	int height;
	Node* leftNode;
	Node* rightNode;
public:
	Node();
	Node(int);
	Node* getLeft() const;
	void setLeft(Node*);
	Node* getRight() const;
	void setRight(Node*);
	int getValue() const;
	void setValue(int);
	int getHeight() const;
	void setHeight(int);
};