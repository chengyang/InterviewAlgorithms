#include <iostream>
#include "../common/linked_list.h"

void RemoveNode(Node* node) {
	if (node == nullptr) {
		printf("RemoveNode, node is null\n");
	}
	Node* iter = node;
	while(iter->next) {
		Node* temp = iter->next;
		*iter = *iter->next;
		iter = temp;
	}
	delete iter;
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
	RemoveNode(node5);
	ll.Print();
	return 0;
}