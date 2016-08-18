#include <iostream>
#include "link_list.h"
#include "bst.h"

void LinkedListTest() {
	LinkList<int> ll;
	ll.Add(new Node<int>(0));
	ll.Add(new Node<int>(1));
	ll.Add(new Node<int>(2));
	ll.Add(new Node<int>(3));

	ll.RemoveFromIndex(3);

	Node<int>* node4 = new Node<int>(4);
	Node<int>* node5 = new Node<int>(5);
	Node<int>* node6 = new Node<int>(6);
	Node<int>* node7 = new Node<int>(7);
	ll.Add(node4);
	ll.Add(node5);
	ll.Add(node6);
	ll.Add(node7);

	ll.RemoveNode(node5);

	ll.Print();
}

void BstTest() {
	Bst<int> bst;
	bst.Insert(bst.root, new BstNode<int>(2));
	bst.Insert(bst.root, new BstNode<int>(1));
	bst.Insert(bst.root, new BstNode<int>(0));
	bst.Insert(bst.root, new BstNode<int>(3));

	bst.Print(bst.root);
}

int main() {
	// LinkedListTest();
	BstTest();
}