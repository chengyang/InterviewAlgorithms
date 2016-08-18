#include <iostream>
#include "../common/link_list.h"

LinkList<int> SumLinkList(const LinkList<int>& link_list0, 
													const LinkList<int>& link_list1) {
	int carry_over = 0;
	Node<int>* iter0 = link_list0.head;
	Node<int>* iter1 = link_list1.head;

	LinkList<int> new_list;
	while(iter1) {
		int subtotal = iter0->data + iter1->data + carry_over;
		if (subtotal - 9 > 0) {
			carry_over = subtotal - 9;
			new_list.Add(new Node<int>(subtotal - 10));
		} else {
			carry_over = 0;
			new_list.Add(new Node<int>(subtotal));
		}
		iter0 = iter0->next;
		iter1 = iter1->next;
	}

	if (carry_over != 0) {
		new_list.Add(new Node<int>(carry_over));
	}
	return new_list;
}

int main() {
	LinkList<int> l0;
	l0.Add(new Node<int>(3));
	l0.Add(new Node<int>(1));
	l0.Add(new Node<int>(5));
	l0.Print();

	LinkList<int> l2;
	l2.Add(new Node<int>(5));
	l2.Add(new Node<int>(9));
	l2.Add(new Node<int>(4));
	l2.Print();

	LinkList<int> l3 = SumLinkList(l0, l2);
	l3.Print();

	return 0;
}