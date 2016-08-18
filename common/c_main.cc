#include <iostream>
//#include <fstream>

#include "linked_list.h"
#include "stack.h"
#include "queue.h"
#include "binary_tree.h"
#include "util.h"

using namespace std;

void LinkedListTest() {
  LinkedList<float> ll;
  ll.AddNode(new Node<float>(0.5f));
  ll.AddNode(new Node<float>(5.4f));
  ll.AddNode(new Node<float>(2.f));
  ll.AddNode(new Node<float>(3.f));

  Node<float>* node4 = new Node<float>(4.f);
  Node<float>* node5 = new Node<float>(5.f);
  Node<float>* node6 = new Node<float>(6.f);
  Node<float>* node7 = new Node<float>(7.f);
  ll.AddNode(node4);
  ll.AddNode(node5);
  ll.AddNode(node6);
  ll.AddNode(node7);
  ll.Print();
  ll.RemoveNode(node5);
  ll.Print();
}

void StackTest() {
  Stack<int> stack;
  stack.Push(new Node<int>(2));
  stack.Push(new Node<int>(3));
  stack.Push(new Node<int>(9));
  stack.Push(new Node<int>(10));
  stack.Push(new Node<int>(88));
  stack.Print();
  Node<int> node = stack.Pop();
  stack.Print();
  cout << "Element get poped: " << node.data << endl;
}

void QueueTest() {
  Queue<int> q;
  q.Enqueue(new Node<int>(2));
  q.Enqueue(new Node<int>(4));
  q.Enqueue(new Node<int>(6));
  q.Enqueue(new Node<int>(0));
  q.Enqueue(new Node<int>(10));
  q.Print();
  Node<int> node = q.Dequeue();
  q.Print();
  cout << "Element get dequeued: " << node.data << endl;
}

void BinaryTreeTest() {
  // Manually set up a tree;
  BTNode* root = new BTNode(50);
  root->left = new BTNode(20);
  root->right = new BTNode(40);
  root->left->left = new BTNode(10);
  root->left->right = new BTNode(25);
  root->right->left = new BTNode(35);
  root->right->right = new BTNode(50);
  root->left->left->left = new BTNode(5);
  root->left->left->right = new BTNode(15);
  root->left->right->right = new BTNode(28);
  root->right->right->left = new BTNode(41);
  PrintBinaryTree(root, 1, 6, cout);

  // Set up a BST
  int array[] = {5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12};
  int size = sizeof(array) / sizeof(int);

  BinaryTree bt;
  for (int i = 0; i < size; ++i) {
    bt.InsertNode(new BTNode(array[i]));
  }

  bt.Print();
  bt.PostOrderTraverse();
  //  ofstream fout("tree_pretty.txt");
  //  printPretty(root, 5, 0, fout);
}

int main() {
  LinkedListTest();
  StackTest();
  QueueTest();
  BinaryTreeTest();
}