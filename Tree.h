#pragma once
#include <iostream>
using namespace std;
#include "Node.h"
template <class T>
class Tree
{
protected:
	Node<T>* root;
public:
	Tree();
	virtual void insert(T value) = 0;
	virtual bool searching(T value) = 0;
	virtual void preOrder() = 0;
	virtual void postOrder() = 0;
	virtual void inOrder() = 0;
	virtual void preOrder2() = 0;
	virtual void postOrder2() = 0;
	virtual void inOrder2() = 0;


};
template <class T>
Tree<T>::Tree()
{
	root = nullptr;
}
