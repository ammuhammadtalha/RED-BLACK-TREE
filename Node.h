#pragma once
template <class T>
struct Node
{
	T data;
	Node<T>* left;
	Node<T>* right;
	char colour;
	Node()
	{
		data = '\0';
		left = right = nullptr;
	}
};