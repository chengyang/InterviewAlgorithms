#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "node.h"

template <class T>
class LinkedList {
 public:
  size_t length;
  Node<T>* head;
  Node<T>* tail;

  LinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
  }
  ~LinkedList() {}

  void AddNode(Node<T>* node) {
    if (!head) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
    length++;
  }

  void RemoveNode(Node<T>* node) {
    Node<T>* it = head;
    Node<T>* it_pre;

    if (node == head) {
      head = head->next;
      delete it;
      length--;
      return;
    }

    while (it) {
      if (it == node) {
        it_pre->next = it->next;
        delete it;
        length--;
        return;
      }
      it_pre = it;
      it = it->next;
    }
  }

  void Print() {
    Node<T>* it = head;
    std::cout << "LinkedList: ";
    while (it != nullptr) {
      std::cout << it->data << " ";
      it = it->next;
    }
    std::cout << std::endl;
  }
};
#endif  // LINKED_LIST_H