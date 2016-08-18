#ifndef UTIL_H
#define UTIL_H

#include <deque>
#include <iomanip>
#include <sstream>
#include <string>

#include "node.h"

#define MAX_INT ~(1 << (sizeof(int) * 8 - 1))
#define MIN_INT 1 << (sizeof(int) * 8 - 1)
// O(logn)
int pow(int m, int n) {
  int result = 1;
  while (n > 0) {
    if (n & 1) {
      result *= m;
    }
    m *= m;
    n >>= 1;
  }
  return result;
}

bool GetBit(int value, int position) {
  int result = value & (1 << position);
  return result != 0;
}

int SetBit(int value, int position, bool is_one) {
  if (is_one) {
    return value | 1 << position;
  } else {
    return value & ~(1 << position);
  }
}

int FlipBit(int value, int position) {
  bool is_one = GetBit(value, position);
  return SetBit(value, position, !is_one);
}

// Convert an integer value to string
std::string intToString(int val) {
  std::ostringstream ss;
  ss << val;
  return ss.str();
}

// Find the maximum height of the binary tree
int maxHeight(BTNode* p) {
  if (!p) return 0;
  int leftHeight = maxHeight(p->left);
  int rightHeight = maxHeight(p->right);
  return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Print the arm branches (eg, /    \ ) on a line
void printBranches(int branchLen, int nodeSpaceLen, int startLen,
                   int nodesInThisLevel, const std::deque<BTNode*>& nodesQueue,
                   std::ostream& out) {
  std::deque<BTNode*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++) {
    out << ((i == 0) ? std::setw(startLen - 1) : std::setw(nodeSpaceLen - 2))
        << "" << ((*iter++) ? "/" : " ");
    out << std::setw(2 * branchLen + 2) << "" << ((*iter++) ? "\\" : " ");
  }
  out << std::endl;
}

// Print the branches and node (eg, ___10___ )
void printNodes(int branchLen, int nodeSpaceLen, int startLen,
                int nodesInThisLevel, const std::deque<BTNode*>& nodesQueue,
                std::ostream& out) {
  std::deque<BTNode*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? std::setw(startLen) : std::setw(nodeSpaceLen)) << ""
        << ((*iter && (*iter)->left) ? std::setfill('_') : std::setfill(' '));
    out << std::setw(branchLen + 2)
        << ((*iter) ? intToString((*iter)->data) : "");
    out << ((*iter && (*iter)->right) ? std::setfill('_') : std::setfill(' '))
        << std::setw(branchLen) << "" << std::setfill(' ');
  }
  out << std::endl;
}

// Print the leaves only (just for the bottom row)
void printLeaves(int indentSpace, int level, int nodesInThisLevel,
                 const std::deque<BTNode*>& nodesQueue, std::ostream& out) {
  std::deque<BTNode*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? std::setw(indentSpace + 2) : std::setw(2 * level + 2))
        << ((*iter) ? intToString((*iter)->data) : "");
  }
  out << std::endl;
}

// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the
// minimum space between nodes, while level 2 has a larger space between
// nodes)
// indentSpace  Change this to add some indent space to the left (eg,
// indentSpace of 0 means the lowest level of the left node will stick to the
// left margin)
void PrintBinaryTree(BTNode* root, int level, int indentSpace,
                     std::ostream& out) {
  int h = maxHeight(root);
  int nodesInThisLevel = 1;

  int branchLen = 2 * (pow(2, h) - 1) -
                  (3 - level) * pow(2,
                                    h - 1);  // eq of the length of branch for
                                             // each node of each level
  int nodeSpaceLen =
      2 + (level + 1) * pow(2, h);  // distance between left neighbor
  // node's right arm and right
  // neighbor node's left arm
  int startLen = branchLen + (3 - level) +
                 indentSpace;  // starting space to the first node to print of
  // each level (for the left most node of each
  // level only)

  std::deque<BTNode*> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel,
                  nodesQueue, out);
    branchLen = branchLen / 2 - 1;
    nodeSpaceLen = nodeSpaceLen / 2 + 1;
    startLen = branchLen + (3 - level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue,
               out);

    for (int i = 0; i < nodesInThisLevel; i++) {
      BTNode* currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode) {
        nodesQueue.push_back(currNode->left);
        nodesQueue.push_back(currNode->right);
      } else {
        nodesQueue.push_back(NULL);
        nodesQueue.push_back(NULL);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue,
                out);
  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}

#endif  // UTIL