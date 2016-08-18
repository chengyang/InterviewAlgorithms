#include <iostream>
#include <vector>
#include "../common/node.h"
#include "../common/util.h"
#include "../common/linked_list.h"

int depth = 0;
std::vector<LinkedList> lists;
void GetLinkedListFromTree(BTNode* root) {
  if (!root) return;
  depth++;
  if (lists.size() < depth) {
    LinkedList ll;
    ll.AddNode(new Node(root->data));
    lists.push_back(ll);
  } else {
    lists[depth - 1].AddNode(new Node(root->data));
  }
  GetLinkedListFromTree(root->left);
  GetLinkedListFromTree(root->right);
  depth--;
}

int main() {
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
  PrintBinaryTree(root, 1, 6, std::cout);

  GetLinkedListFromTree(root);
  for (std::vector<LinkedList>::iterator it = lists.begin(); it != lists.end();
       ++it) {
    it->Print();
  }
  std::cout << lists.size() << std::endl;
  // for(vect)
  return 0;
}
