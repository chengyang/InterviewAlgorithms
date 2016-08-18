#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <iostream>
#include "node.h"
#include "util.h"

class BinaryTree {
 public:
  BTNode* root;
  int depth;

  BinaryTree() {
    root = nullptr;
    depth = 0;
  }
  ~BinaryTree() {}

  void InsertNode(BTNode* node) { Insert(root, node); }
  void Print() { PrintBinaryTree(root, 1, 6, std::cout); }

  void InOrderTraverse() { InOrder(root); }
  void PreOrderTraverse() { PreOrder(root); }
  void PostOrderTraverse() { PostOrder(root); }

 private:
  void Insert(BTNode*& root, BTNode* node) {
    if (root == nullptr) {
      root = node;
      return;
    }
    if (node->data < root->data) {
      Insert(root->left, node);
    } else {
      Insert(root->right, node);
    }
  }
  void InOrder(BTNode* root) {
    if (!root) return;
    InOrder(root->left);
    std::cout << root->data << ",";
    InOrder(root->right);
  }

  void PreOrder(BTNode* root) {
    if (!root) return;
    std::cout << root->data << ",";
    PreOrder(root->left);
    PreOrder(root->right);
  }

  void PostOrder(BTNode* root) {
    if (!root) return;
    depth++;
    PostOrder(root->left);
    PostOrder(root->right);
    std::cout << root->data << ", d:" << depth << std::endl;
    depth--;
  }
};
#endif  // BINARY_TREE_H_