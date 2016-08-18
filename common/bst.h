#include <iostream>

template <class T>
class BstNode {
public:
	BstNode(T t) {
		data = t;
		left_child = nullptr;
		right_child = nullptr;
	}
	~BstNode();

	BstNode<T>* left_child;
	BstNode<T>* right_child;
	T data;
};


template <class T>
class Bst {
public:
	Bst() { root = nullptr; }
	~Bst() {}

	void Insert(BstNode<T>* &local_root, BstNode<T>* node) {
		if (!node) return;

		if (local_root == nullptr) {
			local_root = node;
			return;
		}

		if (node->data <= local_root->data) {
			Insert(local_root->left_child, node);
		} else {
			Insert(local_root->right_child, node);
		}
	}

	void Print(BstNode<T>* local_root) {
		// in-order traversal
		if (!root) return;

		if (local_root->left_child) {
			Print(local_root->left_child);
		}
		if (local_root->right_child) {
			Print(local_root->right_child);
		}
		PrintNode(*local_root);
	}

	void PrintNode(const BstNode<T>& t) {
		printf("%d, ", t.data);
	}

	BstNode<T>* root;
};