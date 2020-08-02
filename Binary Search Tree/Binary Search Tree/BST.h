#pragma once

#include <iostream>

// Implements generic typing 

template <typename T>
struct Node {
	int count = 1;
	T value;
	Node* left = nullptr;
	Node* parent = nullptr;
	Node* right = nullptr;

	Node(T value, Node* parent) {
		this->value = value;
		this->parent = parent;
	}
};

// Binary search tree
template <typename T>
class BST {
private:
	// root Node
	Node<T>* root = nullptr;

	// Min node relative to another node
	Node<T>* min_node(Node<T>* node) {
		Node<T>* current = node;

		while (current->left != nullptr) {
			current = current->left;
		}

		return current;
	}

	// Max node relative to another node 
	Node<T>* max_node(Node<T>* node) {
		Node<T>* current = node;

		while (current->right != nullptr) {
			current = current->right;
		}

		return current;
	}

public:
	// Constructor 
	BST() {}

	//insert value in node
	Node<T>* insert(T value) {
		if (this->root == nullptr) {
			this->root = new Node<T>(value, nullptr);
			return this->root;
		}

		// The node being iterated on
		Node<T>* current = this->root;

		// Loop tell spot is allocated for new node
		while (true) {
			if (current->value == value) {
				current->count++;
				return current;
			}
			// If value is less then nodes value go right
			else if (current->value < value) {
				if (current->right == nullptr) {
					current->right = new Node<T>(value, current);
					return current->right;
				}
				else {
					current = current->right;
				}
			}
			// If value is less then nodes value go left
			else {
				if (current->left == nullptr) {
					current->left = new Node<T>(value, current);
					return current->left;
				}
				else {
					current = current->left;
				}
			}
		}
	}

	// Finds the node by value 
	Node<T>* search(T value) {
		Node<T>* current = this->root;

		// loops tell finds the node with correct value
		while (current != nullptr) {
			if (current->value == value) {
				return current;
			}
			else if (current->value < value) {
				current = current->right;
			}
			else {
				current = current->left;
			}
		}

		// if no node is found return null pointer
		return nullptr;
	}


	// remove node by value in the given tree
	bool remove(T value) {
		Node<T>* node = this->search(value);

		if (node == nullptr) {
			return false;
		}

		return remove(node);
	}

	// remove a node given the pointer
	bool remove(Node<T>* node) {
		// if node count higher then one decrement count
		if (node->count > 1) {
			node->count--;
		}
		// If node being deleted has no children
		else if (node->right == nullptr && node->left == nullptr) {
			if (node == this->root) {
				root = nullptr;
				delete node;
				return true;
			}

			// Delete node and set parent to right 
			else if (node->parent->right == node) {
				node->parent->right = nullptr;
				delete node;
				return true;
			}
			// Delete node and set parent to left
			else if (node->parent->left == node) {
				node->parent->left = nullptr;
				delete node;
				return true;
			}

			return false;
		}

		// checks if there is a right child and no left
		else if (node->right != nullptr && node->left == nullptr) {
			if (node == this->root) {
				root = node->right;
				delete node;
				return true;
			}
			// delete node repair chain
			else if (node->parent->right == node) {
				node->parent->right = node->right;

				if (node->right != nullptr) {
					node->right->parent = node->parent;
				}
				delete node;
				return true;
			}
			// if left node = right node
			else if (node->parent->left == node) {
				node->parent->left = node->right;
				if (node->right != nullptr) {
					node->right->parent = node->parent;
				}
				delete node;
				return true;
			}
			return false;
		}
		//Checks left value 
		else if (node->right == nullptr && node->left != nullptr) {
			if (node == this->root) {
				this->root = node->left;
				delete node;
				return true;
			}
			//if right node = left node
			else if (node->parent->right == node) {
				node->parent->right = node->left;
				if (node->left != nullptr) {
					node->left->parent = node->parent;
				}
				delete node;
				return true;
			}
			// if left = left node 
			else if (node->parent->left == node) {
				node->parent->left = node->left;
				if (node->left != nullptr) {
					node->left->parent = node->parent;
				}
				delete node;
				return true;
			}
			return false;
		}
		// if left and right are not null
		else if (node->right != nullptr && node->left != nullptr) {
			Node<T>* right_lowest = this->min_node(node->right);

			node->value = right_lowest->value;


			return this->remove(right_lowest);
		}
		else {
			return false;
		}
	}

	// Loop tree in order low to high
	void inorder(std::ostream& out) {
		out << "Tree Inorder: ";
		this->inorder(out, this->root);
		out << "\b\b";
	}
	// Recurrive loop 
	void inorder(std::ostream& out, Node<T>* node) {
		if (node == nullptr) {
			return;
		}

		this->inorder(out, node->left);
		out << node->value;
		if (node->count > 1) {
			out << " (" << node->count << ")";
		}
		out << ", ";
		this->inorder(out, node->right);
	}

	

	// finds min
		T min() {
			Node<T>* node = this->min_node(this->root);

			return node->value;
		}

	// finds max
		T max() {
			Node<T>* node = this->max_node(this->root);

			return node->value;
		}
};