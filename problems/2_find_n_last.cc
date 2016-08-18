#include <iostream>

#include "../common/linked_list.h"

void FindNfromLast(const LinkedList& ll, int n) {
    if(n>=ll.length)
        return;
    int count = 0;
    Node* p = ll.head;
    while (p!=nullptr) {
        if (count==ll.length-n) {
            printf("Found %d to the last node: %d\n", n, p->data);
            return;
        }
        p=p->next;
        count++;
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
    
    FindNfromLast(ll, 5);
    
    ll.Print();
    return 0;
}