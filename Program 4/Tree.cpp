#include "Tree.h"


Tree::Tree()
{
	root = nullptr;
	value = 0;
}

void Tree::traverse()
{
	Node* p = root;
	bool endTree = false;
	cout << "\nNon-recursive traverse.\n" << endl;
	while (endTree == false)
	{
		while (p != nullptr)
		{
			cout << p->getValue() << endl;
			s.push(p);
			p = p->getLeft();
		}
		if (!s.empty())
		{
			if (p == nullptr)
			{
				p = s.top();
				s.pop();
			}
			if (p->getRight() != nullptr)
				p = p->getRight();
			while (p->getRight() == nullptr && endTree == false)
			{
				if (!s.empty())
				{
					p = s.top();
					s.pop();
				}
				else
					endTree = true;
			}
			p = p->getRight();
		}
	}
}

void Tree::traverseRecursive()
{
	cout << "\nRecursive traverse.\n" << endl;
	if (root != nullptr)
		traverseRecursiveHelper(root);
	else
		cout << "Tree is empty.";
}

void Tree::traverseRecursiveHelper(Node* p)
{
	if (p != nullptr)
	{
		traverseRecursiveHelper(p->getLeft());
		cout << p->getValue() << endl;
		traverseRecursiveHelper(p->getRight());
	}
}

void Tree::insert(int newValue)
{
	Node* p;
	if (root == nullptr)
	{
		p = new Node(newValue);
		root = p;
	}
	else
	{
		p = root;
		insertHelper(p, newValue);
	}
	balance(p);

}

Node* Tree::insertHelper(Node* p, int newValue)
{
	if (!p)
		return new Node(newValue);
	if (newValue < p->getValue())
	{
		p->setLeft(insertHelper(p->getLeft(), newValue));
	}
	else if (newValue > p->getValue())
	{
		p->setRight(insertHelper(p->getRight(), newValue));
	}
	else
		return p;
}

void Tree::balance(Node* p)
{
	setHeight(p);
	while (!s.empty())
	{
		p = s.top();
		Node* z = nullptr;
		if (balanceTree(p) > 1)
		{
			if (balanceTree(p->getLeft()) < 0)
				p->setLeft(rotateRight(p->getLeft()));
			z = rotateLeft(p);
			if (z != root)
				placeNode(z);
		}
		if (balanceTree(p) < -1)
		{
			if (balanceTree(p->getRight()) > 0)
				p->setRight(rotateLeft(p->getRight()));
			z = rotateRight(p);
			if (z != root)
				placeNode(z);
		}
		if (!s.empty())
			s.pop();
	}
}

Node* Tree::rotateRight(Node* p)
{
	Node* z = p->getRight();
	if (z->getLeft() != nullptr)
	{
		Node* temp = z;
		while (p->getValue() < temp->getValue() && temp->getLeft() != nullptr)
			temp = temp->getLeft();
		while (p->getValue() > temp->getValue() && temp->getRight() != nullptr)
			temp = temp->getRight();
		if (temp->getLeft() == nullptr)
			p->setRight(nullptr);
		temp->setLeft(p);
	}
	else
	{
		if (z->getLeft() == nullptr)
			p->setRight(nullptr);
		z->setLeft(p);
	}
	p->setHeight(0);
	z->setHeight(0);
	while (!s.empty())
		s.pop();
	if (p == root)
	{
		setHeight(root);
		root = z;
	}
	return z;
}

Node* Tree::rotateLeft(Node* p)
{
	Node* z = p->getLeft();
	if (z->getRight() != nullptr)
	{
		Node* temp = z;
		while (p->getValue() < temp->getValue() && temp->getLeft() != nullptr)
			temp = temp->getLeft();
		while (p->getValue() > temp->getValue() && temp->getRight() != nullptr)
			temp = temp->getRight();
		if (temp->getRight() == nullptr)
			p->setLeft(nullptr);
		temp->setRight(p);
	}
	else
	{ 
		if (z->getRight() == nullptr)
			p->setLeft(nullptr);
		z->setRight(p);
	}
	p->setHeight(0);
	z->setHeight(0);
	while (!s.empty())
		s.pop();
	if (p == root)
	{
		setHeight(root);
		root = z;
	}
	return z;
}

void Tree::placeNode(Node* z)
{
	Node* p = root;
	while (p != z)
	{
		if (p == nullptr)
			p = z;
		else 
		{
			if (p->getRight() == z->getRight() || p->getRight() == z->getLeft())
			{
				p->setRight(z);
				p = z;
			}
			else if (p->getLeft() == z->getLeft() || p->getLeft() == z->getRight() )
			{
				p->setLeft(z);
				p = z;
			}
			else if (p->getValue() > z->getValue() && p->getLeft() != z->getRight() && p->getLeft() != nullptr)
			{
				Node* temp = z;
				while (p->getLeft() != temp && temp->getRight() != nullptr)
					temp = temp->getRight();
				 if (p->getLeft() == temp || p->getLeft() == nullptr)
				{
					p->setLeft(z);
					p = z;
				}
				else
					p = p->getLeft();
			}
			else if (p->getValue() < z->getValue() && p->getRight() != z->getLeft() && p->getRight() != nullptr)
			{
				Node* temp = z;
				while (p->getRight() != temp && temp->getLeft() != nullptr)
					temp = temp->getLeft();
				if (p->getRight() == temp || p->getRight() == nullptr)
				{
					p->setRight(z);
					p = z;
				}
				else
					p = p->getRight();
			}
		}
	}
	while (!s.empty())
		s.pop();
	setHeight(root);
}

void Tree::setHeight(Node* p)
{
	int hl = 0;
	int hr = 0;
	if (p->getLeft() != nullptr)
	{
		hl += setHeightHelperLeft(p->getLeft());
		setHeight(p->getLeft());
	}
	if (p->getRight() != nullptr)
	{
		hr += setHeightHelperRight(p->getRight());
		setHeight(p->getRight());
	}
	p->setHeight(hl - hr);
	s.push(p);
}

int Tree::setHeightHelperLeft(Node* p)
{
	if (p->getLeft() != nullptr)
		return treeHeight(p) + setHeightHelperLeft(p->getLeft());
	else if (p->getRight() != nullptr)
		return treeHeight(p) + setHeightHelperLeft(p->getRight());
	else
		return treeHeight(p);
}

int Tree::setHeightHelperRight(Node* p)
{
	if (p->getRight() != nullptr)
		return treeHeight(p) + setHeightHelperRight(p->getRight());
	else if (p->getLeft() != nullptr)
		return treeHeight(p) + setHeightHelperRight(p->getLeft());
	else
		return treeHeight(p);
}
int Tree::balanceTree(Node* p)
{
	return p->getHeight();
}

int Tree::treeHeight(Node* p)
{
	return p ? 1 : 0;
}

void Tree::deleteTree(Node* p)
{
	Node* q = nullptr;
		if (p != nullptr)
		{
			s.push(p);
			deleteTree(p->getLeft());
			s.pop();
			if (!s.empty())
				q = s.top();
			if (s.empty())
			{
				delete p;
				p = nullptr;
			}
			else
			{
				if (q->getLeft() != nullptr)
				{
					delete p;
					q->setLeft(nullptr);
					p = q;
				}
				deleteTree(p->getRight());
				if (q->getRight() != nullptr)
				{
					delete p;
					q->setRight(nullptr);
					p = q;
				}
			}
		}
}

Tree::~Tree()
{
	deleteTree(root);
}