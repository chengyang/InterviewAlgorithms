#ifndef NODE_H_
#define NODE_H_

// Binary tree node
struct BTNode {
  BTNode* left;
  BTNode* right;
  int data;
  BTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

template <typename T>
// Normal node for LinkedList, Stack and Queue
struct Node {
  Node* next;
  T data;
  Node(T val) : data(val), next(nullptr) {}
};
#endif  // NODE_H_