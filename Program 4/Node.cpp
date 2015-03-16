#include "Node.h"


Node::Node()
{
	value = 0;
	height = 0;
	leftNode = 0;
	rightNode = 0;
}

Node::Node(int newValue)
{
	value = newValue;
	leftNode = 0;
	rightNode = 0;
	height = 0;
}

Node* Node::getLeft() const
{
	return leftNode;
}

void Node::setLeft(Node* lNode)
{
	leftNode = lNode;
}

Node* Node::getRight() const
{
	return rightNode;
}

void Node::setRight(Node* rNode)
{
	rightNode = rNode;
}

int Node::getValue() const
{
	return value;
}

void Node::setValue(int newValue)
{
	value = newValue;
}

int Node::getHeight() const
{
	return height;
}

void Node::setHeight(int newHeight)
{
	height = newHeight;
}