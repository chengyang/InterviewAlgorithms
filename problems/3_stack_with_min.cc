#include <iostream>
#include "../common/stack.h"

using namespace std;

class StackWithMin {
 public:
  StackWithMin() {}
  ~StackWithMin() {}
  void Push(Node* node) {
    if (!s1.top || node->data < s2.Peek()) {
      s2.Push(node);
    }
    s1.Push(node);
  }
  Node Pop() {
    Node n = s1.Pop();
    if (n.data == s2.Peek()) {
      s2.Pop();
    }
    return n;
  }
  int GetMin() { return s2.Peek(); }

 private:
  Stack s1;
  Stack s2;
};

int main() {
  StackWithMin stack;
  stack.Push(new Node(10));
  stack.Push(new Node(3));
  stack.Push(new Node(1));
  stack.Push(new Node(3));
  stack.Push(new Node(9));
  stack.Push(new Node(10));
  stack.Push(new Node(88));
  cout << "The min is:" << stack.GetMin() << endl;
  return 0;
}