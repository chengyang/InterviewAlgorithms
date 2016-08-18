#include <iostream>
#include "../common/linked_list.h"

void RemoveDup(LinkedList* ll) {
  if (ll->length <= 1) return;
  Node* p1;
  Node* p2;
  p1 = ll->head;
  p2 = p1->next;
  while (p1->next != nullptr) {
    while (p2 != nullptr) {
      if (p1->data == p2->data) {
        Node* temp = p2;
        p2 = p2->next;
        ll->RemoveNode(temp);
      } else {
        p2 = p2->next;
      }
    }
    p1 = p1->next;
    p2 = p1->next;
  }
}

int main() {
  LinkedList ll;
  ll.AddNode(new Node(1));
  ll.AddNode(new Node(1));
  ll.AddNode(new Node(2));
  ll.AddNode(new Node(0));

  Node* node4 = new Node(1);
  Node* node5 = new Node(5);
  Node* node6 = new Node(8);
  Node* node7 = new Node(1);
  ll.AddNode(node4);
  ll.AddNode(node5);
  ll.AddNode(node6);
  ll.AddNode(node7);
  ll.Print();

  RemoveDup(&ll);

  ll.Print();
  return 0;
}