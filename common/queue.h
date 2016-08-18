#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include "node.h"

template <class T>
class Queue {
 public:
  Node<T>* first;
  Node<T>* last;

  Queue() {
    first = nullptr;
    last = nullptr;
  }
  ~Queue() {}

  void Enqueue(Node<T>* node) {
    if (!first) {
      first = node;
      last = node;
    } else {
      Node<T>* f = node;
      f->next = first;
      first = f;
    }
  }

  Node<T> Dequeue() {
    Node<T>* it = first;
    while (it->next != last) {
      it = it->next;
    }
    Node<T>* ret = last;
    it->next = nullptr;
    last = it;
    return *ret;
  }

  void Print() {
    Node<T>* it = first;
    printf("Queue: ");
    while (it != nullptr) {
      std::cout << it->data << " ";
      it = it->next;
    }
    std::cout << std::endl;
  }
};
#endif  // QUEUE_H_