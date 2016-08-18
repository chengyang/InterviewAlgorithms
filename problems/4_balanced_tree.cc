#include <iostream>
#include "../common/node.h"
#include "../common/util.h"

using namespace std;

int d, num, depths[100];

void GetDepths(BTNode* root) {
  if (!root) return;
  ++d;
  GetDepths(root->left);
  if ((!root->left) && (!root->right)) {
    depths[num++] = d;
  }
  GetDepths(root->right);
  --d;
}

bool IsBalanced(BTNode* root) {
  if (!root) return false;
  GetDepths(root);
  int max = depths[0], min = depths[0];
  cout << "Depths: ";
  for (int i = 0; i < num; ++i) {
    max = std::max(max, depths[i]);
    min = std::min(min, depths[i]);
    cout << depths[i] << ", ";
  }
  cout << endl;
  if (max - min > 1)
    return false;
  else
    return true;
}

int main() {
  BTNode* root = new BTNode(30);
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
  cout << (IsBalanced(root) ? "Is balanced" : "Is not balanced") << endl;

  return 0;
}