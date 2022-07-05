#include "RBT.h"
void menu()
{
	cout << "    -------------------------------------------------------------------------------------------------- \n";
	cout << "    ==                                                                                              == \n";
	cout << "    ==                  Press 1 to insert values in the tree (one by one)                           == \n";
	cout << "    ==                  Press 2 for searching a value from the tree                                 == \n";
	cout << "    ==                  Press 3 for pre-order traversal NLR                                         == \n";
	cout << "    ==                  Press 4 for in-order traversal LNR                                          == \n";
	cout << "    ==                  Press 5 for post-order traversal LRN                                        == \n";
	cout << "    ==                  Press 6 for pre-order traversal 2 NRL                                       == \n";
	cout << "    ==                  Press 7 for in-order traversal 2 RNL                                        == \n";
	cout << "    ==                  Press 8 for post-order traversal 2 RLN                                      == \n";
	cout << "    ==                  Press 9 for displaying parent of a node present in Tree                     == \n";
	cout << "    ==      Press 10 to read integer values from the file 'input.txt' to create a red - black tree  == \n";
	cout << "    ==                  Press 11 to delete all duplicate values from the tree                       == \n";
	cout << "    ==                  Press 12 to destroy the complete tree                                       == \n";
	cout << "    ==                  Press 13 to EXIT                                                            == \n";
	cout << "    ==                                                                                              == \n";
	cout << "    -------------------------------------------------------------------------------------------------- \n";
}

int main()
{
	RBT<int> b;
	while (true)
	{
		int choice = 0;
		menu();
		cout << " Enter your choice = ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << " Enter Value which you want to insert = ";
			int val;
			cin >> val;
			b.insert(val);
			cout << " Value is inserted Successfully................ \n";
			break;

		case 2:
			cout << " Enter Value which you want to search = ";
			int data;
			cin >> data;
			bool flag;
			flag = b.searching(data);
			
			if (flag == true)
			{
				cout << " Value is Found in the Tree \n";
			}
			else
			{
				cout << " Value is not Found in the Tree \n";
			}
			break;

		case 3:
			cout << "  Pre-order Traversal NLR = ";
			b.preOrder();
			cout << endl;
			break;

		case 4:
			cout << " In-order Traversal LNR = ";
			b.inOrder();
			cout << endl;
			break;

		case 5:
			cout << " Post-order Traversal LRN = ";
			b.postOrder();
			cout << endl;
			break;

		case 6:
			cout << " Pre-order Traversal 2 NRL = ";
			b.preOrder2();
			cout << endl;
			break;

		case 7:
			cout << " In-order traversal 2 RNL = ";
			b.inOrder2();
			cout << endl;
			break;

		case 8:
			cout << " Post-order traversal 2 RLN = ";
			b.postOrder2();
			cout << endl;
			break;

		case 9:
			int value;
			cout << " Enter Node Value to find parent of a node present in Tree = ";
			cin >> value;
			b.searchParent(value);
			
			break;

		case 10:
			b.readFile();
			break;

		case 11:
			cout << "Delete all duplicate values from the tree is not alowed because in redbalck tree duplicate values cannot be inserted \n";

			break;

		case 12:
			b.deletion();
			cout << " Tree is destroyed succesfully.......... \n";
			break;

		case 13:
			cout << " Your program is terminated...........  \n";
			goto exit_loop;
		default:
			cout << " You have Enterd wrong choice \n ";
			break;
		}
	}
	exit_loop:
	return 0;
}