#include <iostream>
#include "../common/node.h"
#include "../common/util.h"

int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
void CreateMinTree(BTNode*& root, int start, int end) {
  if (start <= end) {
    int middle = (start + end) / 2;
    root = new BTNode(array[middle]);
    CreateMinTree(root->left, start, middle - 1);
    CreateMinTree(root->right, middle + 1, end);
  }
}
int main() {
  BTNode* root;
  CreateMinTree(root, 0, 8);
  PrintBinaryTree(root, 1, 6, std::cout);
  return 0;
}
