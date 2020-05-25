#include "Header.h"
void List::Add(data x) {
	Node* temp = new Node;
	temp->Next = Head;
	temp->x = x;
	size++;
	if (Head != NULL) {
		Last = Present;
		Present = temp;
		Present->Next = Last->Next;
		Last->Next = temp;
	}
	else {
		Head = Last = Present = temp;
		Last->Next = Head;
	}
}

void List::Show() {
	std::cout << Present->x << std::endl;
};

List::~List() {
	while (size != 0) {
		Last->Next = Present->Next;
		delete	Present;
		Present = Last->Next;
		size--;
	}
};

void List::next() {
	Last = Present;
	Present = Present->Next;
};

void List::remove() {
	Last->Next = Present->Next;
	delete	Present;
	Present = Last->Next;
	size--;
};
