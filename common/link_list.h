#include <iostream>

template <class T>
class Node {
public:
	Node(T t) {
		data = t;
		next = nullptr;
	}
	~Node() {}

	T data;
	Node<T>* next;
};

template <class T>
class LinkList {
public:
	LinkList() {head = nullptr; tail = nullptr; size = 0;}
	~LinkList() {}

	void Add(Node<T>* node) {
		if (head == nullptr) {
			head = node;
			tail = head;
			size++;
			return;
		}
		tail->next = node;
		tail = node;
		size++;
	}

	void RemoveFromIndex(size_t index) {
		if (index > size - 1) {
			printf("remove over index\n");
			return;
		}

		if (index == 0) {
			// First element case.
			Node<T>* temp;
			temp = head;
			head = head->next;
			delete temp;
			size--;
			return;
		}

		// Iterate through.
		int counter = 0;
		Node<T>* iter = head;
		while (counter + 1 != index) {
			counter++;
			iter = iter->next;
		}

		if (counter + 2 == size) {
			// Remove the last element.
			tail = iter;
			delete iter->next;
		}
		else {
			// Not the last element, nor the first element.
			Node<T>* temp = iter->next;
			iter->next = temp->next;
			delete temp;
		}
		size--;
	}

	void RemoveNode(Node<T>* node) {
		Node<T>* iter = head;
		Node<T>* prev_iter;
		if (node == head) {
			// head case.
			head = head->next;
			delete iter;
			size--;
			return;
		}

		while(iter != nullptr) {
			if (iter == node) {
				prev_iter->next = iter->next;
				delete iter;
				size--;
				return;
			}
			prev_iter = iter;
			iter = iter->next;
		}
	}

	void Print() {
		Node<T>* iter = head;
		printf("linkedlist\n");
		while(iter != nullptr) {
			printf("%d, ", iter->data);
			iter = iter->next;
		}
		printf("\n");
	}

	size_t size;
	Node<T>* head;
	Node<T>* tail;
};