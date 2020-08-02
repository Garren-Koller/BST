
#include <iostream>
#include "BST.h"

using namespace std;


void main() {
	BST<int> tree;


	// Remove value with no values in tree
	cout << "REMOVE VALUE WITH NO VALUES IN TREE:" << endl;
	tree.remove(8);
	tree.inorder(cout);
	cout << "\n";
	cout << "\n";
	// Insert value
	cout << "INSERT VALUES:" << endl;
	tree.insert(8);
	tree.insert(6);
	tree.insert(15);
	tree.insert(24);
	tree.insert(54);
	tree.inorder(cout);
	cout << "\n";
	cout << "\n";

	// Add duplicate values
	cout << "INSERT DUPLICATE VALUE:" << endl;
	tree.insert(8);
	tree.inorder(cout);
	cout << "\n";
	cout << "\n";

	// Remove value
	cout << "REMOVE VALUE NO CHILDREN:" << endl;
	tree.remove(6);
	tree.inorder(cout);
	cout << "\n";
	cout << "\n";
	// Remove value
	cout << "REMOVE VALUE WITH ONE CHILD:" << endl;
	tree.remove(15);
	tree.inorder(cout);

	cout << "\n";
	cout << "\n";

	// Max Node
	cout << "MAX:";
	cout << tree.max() << endl;

	// Min Node
	cout << "MIN:";
	cout << tree.min() << endl;

	// Pause 
	cout << "\n";
	system("pause");

};

