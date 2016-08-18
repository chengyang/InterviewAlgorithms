#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include "node.h"

template <class T>
class Stack {
 public:
  Node<T>* top;

  Stack() { top = nullptr; }
  ~Stack() {}

  void Push(Node<T>* node) {
    Node<T>* t = node;
    t->next = top;
    top = t;
  }

  Node<T> Pop() {
    Node<T>* it;
    if (top != nullptr) {
      it = top;
      top = top->next;
    }
    return *it;
  }
  int Peek() { return top->data; }

  void Print() {
    Node<T>* it = top;
    printf("Stack: ");
    while (it != nullptr) {
      std::cout << it->data << " ";
      it = it->next;
    }
    std::cout << std::endl;
  }
};
#endif  // STACK_H