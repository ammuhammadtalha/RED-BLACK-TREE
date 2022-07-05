#pragma once
#include "Tree.h"
#include <fstream>
template <class T>
class RBT :public Tree<T>
{
	void CHECKWHOLETREE(Node<T>* , Node<T>* , Node<T>* , Node<T>*);
	bool SEARCHING(Node<T>*, int);
	void PREORDER(Node<T>* );
	void POSTORDER(Node<T>* );
	void INORDER(Node<T>* );
	void PREORDER2(Node<T>* );
	void POSTORDER2(Node<T>* );
	void INORDER2(Node<T>* );
	void DELETION(Node<T>*);
public:
	void insert(T );
	bool searching(T );
	void preOrder();
	void postOrder();
	void inOrder();
	void preOrder2();
	void postOrder2();
	void inOrder2();
	void deletion();
	void readFile();
	void searchParent(int value);
	// CASES
	void reColour(Node<T>*, Node<T>*, Node<T>*);
	void changeColour(Node<T>*, Node<T>*, Node<T>*);
	void uncle(Node<T>* newNode, Node<T>* p, Node<T>* grParent);
	void LL(Node<T>* newNode, Node<T>* p, Node<T>* grParent);
	void LR(Node<T>* newNode, Node<T>* p, Node<T>* grParent);
	void RR(Node<T>* newNode, Node<T>* p, Node<T>* grParent);
	void RL(Node<T>* newNode, Node<T>* p, Node<T>* grParent);
	void checkWholeTree();
	
};
// INSERTION IN THE TREE 
template <class T>
void  RBT<T>::insert(T value)
{
	bool chk = false;
	if (Tree<T>::root != nullptr && searching(value))
	{
		chk = true;
	}
	if (!chk)
	{

		Node<T>* grParent = Tree<T>::root;
		Node<T>* curr_root = Tree<T>::root;
		Node<T>* p = new Node<T>;
		if (Tree<T>::root == nullptr)
		{
			Node<T>* newNode = new Node<T>;
			newNode->data = value;
			newNode->colour = 'B';
			Tree<T>::root = newNode;
		}
		else
		{
			while (curr_root != nullptr)
			{
				if (value < curr_root->data)
				{
					grParent = p;
					p = curr_root;
					curr_root = curr_root->left;
				}
				else
				{
					grParent = p;
					p = curr_root;
					curr_root = curr_root->right;
				}
			}
			if (value < p->data)
			{

				Node<T>* newNode = new Node<T>;
				newNode->data = value;
				newNode->colour = 'R';
				p->left = newNode;

				reColour(newNode, grParent, p);
				uncle(newNode, p, grParent);
				LL(newNode, p, grParent);
				LR(newNode, p, grParent);
				RR(newNode, p, grParent);
				RL(newNode, p, grParent);
				checkWholeTree();
			}
			else
			{
				Node<T>* newNode = new Node<T>;
				newNode->data = value;
				newNode->colour = 'R';
				p->right = newNode;

				reColour(newNode, grParent, p);
				uncle(newNode, p, grParent);
				LL(newNode, p, grParent);
				LR(newNode, p, grParent);
				RR(newNode, p, grParent);
				RL(newNode, p, grParent);
				checkWholeTree();
			}
		}
	}
}
// SEARCHING FROM THE TREE
template <class T>
bool RBT<T>::SEARCHING(Node<T>* n, int value)
{
	bool flag = false;

	if (n != nullptr)
	{
		flag = SEARCHING(n->left, value);
		if (n->data == value)
		{
			flag = true;
			return flag;
		}
		flag = SEARCHING(n->right, value);
	}
	return flag;
}
template <class T>
bool RBT<T>::searching(T value)
{
	if (Tree<T>::root == nullptr)
	{
		cout << " Tree is Empty, So Value is not Found...... \n";
		return false;
	}
	else
	{
		if (SEARCHING(Tree<T>::root, value) == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
// DESTROY WHOLE TREE
template <class T>
void  RBT<T>::DELETION(Node<T>* n)
{
	if (n != nullptr)
	{
		DELETION(n->left);
		DELETION(n->right);
		delete n;
		n = nullptr;
	}
}
template <class T>
void RBT<T>::deletion()
{
	if (Tree<T>::root != nullptr)
	{
		DELETION(Tree<T>::root);
	}
	else
	{
		cout << " Tree is Empty \n";
	}
	Tree<T>::root = nullptr;
}
// READ FROM FILE
template <class T>
void RBT<T>::readFile()
{
	ifstream fin;
	fin.open("input.txt");
	if (fin.is_open())
	{
		T data = '\0';
		while (!fin.eof())
		{
			fin >> data;
			this->insert(data);
		}
		cout << " Value is inserted from the file successfully........... \n";
	}
	else
	{
		cout << " File is not Found \n";
	}
	fin.close();
}
// SEARCH PARENT NODE OF CHILD NODE
template <class T>
void RBT<T>::searchParent(int value)
{
	bool check = false;
	Node<T>* temp = Tree<T>::root;

	if (Tree<T>::root == nullptr)
	{
		cout << "Tree is Empty......!" << endl;
	}
	else if (value == Tree<T>::root->data)
	{
		cout << " This is root Node Value \n";
	}
	else if(searching(value) == true)
	{
		while (1)
		{
			if (value < temp->data)
			{
				if (temp->left->data == value)
				{
					cout << "Parent Node Value = " << temp->data << " -> " << temp->colour << endl;
					break;
				}
				else
				{
					temp = temp->left;
				}
			}
			else if (value >= temp->data)
			{
				if (temp->right->data == value)
				{
					cout << "Parent Node Value = " << temp->data << " -> " << temp->colour << endl;
					break;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
	}
	else
	{
		cout << " Value is not in the Tree..........\n";
	}
	
}
// TRAVERSING 
template <class T>
void RBT<T>::PREORDER(Node<T>* r)
{
	if (r != nullptr)
	{
		cout << r->data << " -> " << r->colour << ", ";
		PREORDER(r->left);
		PREORDER(r->right);
	}
}
template <class T>
void RBT<T>::preOrder()
{
	if (Tree<T>::root == nullptr)
	{
		cout << " Tree is Empty \n";
	}
	else
	{
		PREORDER(Tree<T>::root);
	}
}
template <class T>
void RBT<T>::POSTORDER(Node<T>* r)
{
	if (r != nullptr)
	{
		POSTORDER(r->left);
		POSTORDER(r->right);
		cout << r->data << " -> " << r->colour << ", ";
	}
}
template <class T>
void RBT<T>::postOrder()
{
	if (Tree<T>::root == nullptr)
	{
		cout << " Tree is Empty \n";
	}
	else
	{
		POSTORDER(Tree<T>::root);
	}
}
template <class T>
void RBT<T>::INORDER(Node<T>* r)
{
	if (r != nullptr)
	{
		INORDER(r->left);
		cout << r->data << " -> " << r->colour << ", ";
		INORDER(r->right);
	}
}
template <class T>
void RBT<T>::inOrder()
{
	if (Tree<T>::root == nullptr)
	{
		cout << " Tree is Empty \n";
	}
	else
	{
		INORDER(Tree<T>::root);
	}
}
template <class T>
void RBT<T>::PREORDER2(Node<T>* r)
{
	if (r != nullptr)
	{
		cout << r->data << " -> " << r->colour << ", ";
		PREORDER2(r->right);
		PREORDER2(r->left);
	}
}
template <class T>
void RBT<T>::preOrder2()
{
	if (Tree<T>::root == nullptr)
	{
		cout << " Tree is Empty \n";
	}
	else
	{
		PREORDER2(Tree<T>::root);
	}
}
template <class T>
void RBT<T>::POSTORDER2(Node<T>* r)
{
	if (r != nullptr)
	{
		POSTORDER2(r->right);
		POSTORDER2(r->left);
		cout << r->data << " -> " << r->colour << ", ";
	}
}
template <class T>
void RBT<T>::postOrder2()
{
	if (Tree<T>::root == nullptr)
	{
		cout << " Tree is Empty \n";
	}
	else
	{
		POSTORDER2(Tree<T>::root);
	}
}
template <class T>
void RBT<T>::INORDER2(Node<T>* r)
{
	if (r != nullptr)
	{
		INORDER2(r->right);
		cout << r->data << " -> " << r->colour << ", ";
		INORDER2(r->left);
	}
}
template <class T>
void RBT<T>::inOrder2()
{
	if (Tree<T>::root == nullptr)
	{
		cout << " Tree is Empty \n";
	}
	else
	{
		INORDER2(Tree<T>::root);
	}
}
// CASES FOR INSERTION
template <class T>
void RBT<T>::reColour(Node<T>* newNode, Node<T>* grParent, Node<T>* p)
{
	if (p->colour == 'R' && newNode->colour == 'R')
	{
		if (Tree<T>::root != grParent)
		{
			if (newNode->data < grParent->data)
			{
				if (grParent->right != nullptr)
				{
					if (grParent->right->colour == 'R')
					{
						changeColour(p, grParent, grParent->right);
					}
				}

			}
			else
			{
				if (grParent->left != nullptr)
				{
					if (grParent->left->colour == 'R')
					{
						changeColour(p, grParent, grParent->left);
					}
						
				}
			}

		}
		else
		{
			if (newNode->data < grParent->data)
			{
				if (grParent->right != nullptr)
				{
					if (grParent->right->colour == 'R')
					{
						changeColour(p, grParent, grParent->right);
					}
						
				}

			}
			else
			{
				if (grParent->left != nullptr)
				{
					if (grParent->left->colour == 'R')
					{
						changeColour(p, grParent, grParent->left);
					}
				}
			}

		}
	}

}
template <class T>
void RBT<T>::changeColour(Node<T>* p, Node<T>* grParent, Node<T>* uncle)
{
	if (p->colour == 'R' || p->colour == 'r')
	{
		p->colour = 'B';
	}
	else
	{
		p->colour = 'R';
	}
	if (grParent == Tree<T>::root || grParent->colour == 'R')
	{
		grParent->colour = 'B';
	}
	else
	{
		grParent->colour = 'R';
	}
	if (uncle->colour == 'R')
	{
		uncle->colour = 'B';
	}
	else
	{
		uncle->colour = 'R';
	}

}
template <class T>
void RBT<T>::uncle(Node<T>* newNode, Node<T>* p, Node<T>* grParent)
{
	if (newNode->colour == 'R' && p->colour == 'R')
	{
		if (grParent == Tree<T>::root)
		{
			if (newNode->data > grParent->data)
			{

				if (grParent->left == nullptr)
				{
					if (p->left != nullptr)
					{
						p->left = nullptr;
						p->right = newNode;
						T temp = p->data;
						p->data = newNode->data;
						newNode->data = temp;
						grParent->right = nullptr;
						p->left = grParent;
						Tree<T>::root = p;
						Tree<T>::root->colour = 'B';
					}

				}
				if (grParent->left == nullptr)
				{

					grParent->right = nullptr;
					p->left = grParent;
					Tree<T>::root = p;
					Tree<T>::root->colour = 'B';
					if (grParent->colour == 'R')
						grParent->colour = 'B';
					else
						grParent->colour = 'R';


				}
			}
			else
			{
				if (grParent->right == nullptr)
				{
					if (p->right != nullptr)
					{
						p->right = nullptr;
						p->left = newNode;
						T temp = p->data;
						p->data = newNode->data;
						newNode->data = temp;
						grParent->left = nullptr;
						p->right = grParent;
						Tree<T>::root = p;
						Tree<T>::root->colour = 'B';
					}

				}
				if (grParent->right == nullptr)
				{
					grParent->left = nullptr;
					p->right = grParent;
					Tree<T>::root = p;
					Tree<T>::root->colour = 'B';
					if (grParent->colour == 'R')
					{
						grParent->colour = 'B';
					}
					else
					{
						grParent->colour = 'R';
					}
				}
			}
		}
		else
		{
			if (newNode->data > grParent->data)
			{

				if (grParent->left == nullptr)
				{
					if (p->left != nullptr)
					{
						p->left = nullptr;
						p->right = newNode;
						T temp = p->data;
						p->data = newNode->data;
						newNode->data = temp;
						grParent->right = nullptr;
						p->right = nullptr;
						temp = p->data;
						p->data = grParent->data;
						grParent->data = temp;
						grParent->left = p;
						grParent->right = newNode;
						if (p->colour == 'R')
						{
							grParent->colour = 'B';
						}
						else
						{
							grParent->colour = 'R';
						}
					}

				}
				if (grParent->left == nullptr)
				{

					grParent->right = nullptr;
					p->right = nullptr;
					T temp = grParent->data;
					grParent->data = p->data;
					p->data = temp;
					grParent->left = p;
					grParent->right = newNode;
					if (p->colour == 'R')
					{
						grParent->colour = 'B';
					}
					else
					{
						grParent->colour = 'R';
					}
				}
			}
			else
			{
				if (grParent->right == nullptr)
				{
					if (p->right != nullptr)
					{
						p->right = nullptr;
						p->left = newNode;
						T temp = p->data;
						p->data = newNode->data;
						newNode->data = temp;
						grParent->left = nullptr;
						p->left = nullptr;
						temp = p->data;
						p->data = grParent->data;
						grParent->data = temp;
						grParent->right = p;
						grParent->left = newNode;
						if (p->colour == 'R')
						{
							grParent->colour = 'B';
						}
						else
						{
							grParent->colour = 'R';
						}
					}

				}
				if (grParent->right == nullptr)
				{
					grParent->left = nullptr;
					p->left = nullptr;
					T temp = grParent->data;
					grParent->data = p->data;
					p->data = temp;
					grParent->right = p;
					grParent->left = newNode;
					if (p->colour == 'R')
					{
						grParent->colour = 'B';
					}
					else
					{
						grParent->colour = 'R';
					}
				}
			}
		}
	}

}

template <class T>
void RBT<T>::LL(Node<T>* newNode, Node<T>* p, Node<T>* grParent)
{
	if (p->colour == 'R' && newNode->colour == 'R')
	{
		if (Tree<T>::root != grParent)
		{
			if (newNode->data < grParent->data)
			{
				if (grParent->right != nullptr)
				{
					if (grParent->right->colour == 'B')
					{
						if (p->colour == 'B')
						{
							p->colour = 'R';
						}
						else
						{
							p->colour = 'B';
						}
						if (grParent->colour == 'R')
						{
							grParent->colour = 'B';
						}
						else
						{
							grParent->colour = 'R';
						}
						grParent->left = nullptr;
						if (p->right != nullptr)
						{
							grParent->left = p->right;
						}
						p->right = grParent;
						Tree<T>::root = p;
					}
				}
			}
		}
		else
		{
			if (newNode->data < grParent->data)
			{
				if (grParent->right != nullptr)
				{
					if (grParent->right->colour == 'B')
					{
						if (p->colour == 'B')
						{
							p->colour = 'R';
						}
							
						else
						{
							p->colour = 'B';
						}
							
						if (grParent->colour == 'R')
						{
							grParent->colour = 'B';
						}
						else
						{
							grParent->colour = 'R';
						}
						grParent->left = nullptr;
						if (p->right != nullptr)
						{
							grParent->left = p->right;
						}
						p->right = grParent;
						Tree<T>::root = p;
						if (Tree<T>::root->colour == 'R')
						{
							Tree<T>::root->colour = 'B';
						}
							
					}
				}
			}
			else
			{
				if (grParent->left != nullptr)
				{
					if (grParent->left->colour == 'B')
					{
						if (p->colour == 'B')
						{
							p->colour = 'R';
						}
							
						else
						{
							p->colour = 'B';
						}
							
						if (grParent->colour == 'R')
						{
							grParent->colour = 'B';
						}
						else
						{
							grParent->colour = 'R';
						}
						grParent->right = nullptr;
						if (p->left != nullptr)
						{
							grParent->right = p->left;
						}
						p->left = grParent;
						Tree<T>::root = p;
						if (Tree<T>::root->colour == 'R')
						{
							Tree<T>::root->colour = 'B';
						}
					}
				}
			}
		}
	}
}
template <class T>
void RBT<T>::LR(Node<T>* newNode, Node<T>* p, Node<T>* grParent)
{
	if (p->colour == 'R' && newNode->colour == 'R')
	{
		if (Tree<T>::root != grParent)
		{
			if (newNode->data < grParent->data)
			{
				if (grParent->right != nullptr)
				{
					if (grParent->right->colour == 'B')
					{
						if (p->right != nullptr)
						{
							T temp = p->data;
							p->data = newNode->data;
							newNode->data = temp;
							p->right = nullptr;
							p->left = newNode;
							LL(newNode, p, grParent);
						}
					}
				}
			}
		}
	}

}
template <class T>
void RBT<T>::RR(Node<T>* newNode, Node<T>* p, Node<T>* grParent)
{
	if (p->colour == 'R' && newNode->colour == 'R')
	{
		if (Tree<T>::root != grParent)
		{
			if (newNode->data > grParent->data)
			{
				if (grParent->left != nullptr)
				{
					if (grParent->left->colour == 'B')
					{
						if (p->colour == 'B')
						{
							p->colour = 'R';
						}
						else {
							p->colour = 'B';
						}
						if (grParent->colour == 'R') {
							grParent->colour = 'B';
						}
						else {
							grParent->colour = 'R';
						}
						grParent->right = nullptr;
						if (p->left != nullptr)
						{
							grParent->right = p->left;
						}
						p->left = grParent;
						Tree<T>::root = p;
					}
				}
			}
		}
		else
		{
			if (newNode->data > grParent->data)
			{
				if (grParent->left != nullptr)
				{
					if (grParent->left->colour == 'B')
					{
						if (p->colour == 'B') {
							p->colour = 'R';
						}
						else {
							p->colour = 'B';
						}
						if (grParent->colour == 'R') {
							grParent->colour = 'B';
						}
						else {
							grParent->colour = 'R';
						}
						grParent->right = nullptr;
						if (p->left != nullptr)
						{
							grParent->right = p->left;
						}
						p->left = grParent;
						Tree<T>::root = p;
						if (Tree<T>::root->colour == 'R'){
							Tree<T>::root->colour = 'B';
						}
					}
				}
			}
		}
	}
}
template <class T>
void RBT<T>::RL(Node<T>* newNode, Node<T>* p, Node<T>* grParent)
{
	if (p->colour == 'R' && newNode->colour == 'R')
	{
		if (Tree<T>::root != grParent)
		{
			if (newNode->data > grParent->data)
			{
				if (grParent->left != nullptr)
				{
					if (grParent->left->colour == 'B')
					{
						if (p->left != nullptr)
						{
							T temp = p->data;
							p->data = newNode->data;
							newNode->data = temp;
							p->left = nullptr;
							p->right = newNode;
							RR(newNode, p, grParent);
						}
					}
				}
			}
		}
	}
}
template <class T>
void RBT<T>::CHECKWHOLETREE(Node<T>* curr, Node<T>* pr, Node<T>* p, Node<T>* pp)
{
	if (curr != nullptr)
	{

		pp = p;
		p = pr;
		pr = curr;
		CHECKWHOLETREE(curr->left, pr, p, pp);
		CHECKWHOLETREE(curr->right, pr, p, pp);
		if (p->colour == 'R' && pr->colour == 'R')
		{
			reColour(pr, p, pp);
			uncle(pr, p, pp);
			LL(pr, p, pp);
			LR(pr, p, pp);
			RR(pr, p, pp);
			RL(pr, p, pp);
		}

	}
}
template <class T>
void RBT<T>::checkWholeTree()
{
	Node<T>* pr = new Node<T>;
	Node<T>* p = new Node<T>;
	Node<T>* pp = new Node<T>;

	if (Tree<T>::root != nullptr)
	{
		CHECKWHOLETREE(Tree<T>::root, pr, p, pp);
	}
}