// Кольцевая очередь FIFO      
#include <iostream>


typedef int data;
struct  Node {
	data x;
	Node* Next;
};

class List {
	Node* Head, * Last, * Present;               
	int size;      
public:
	List() :Head(nullptr), Last(nullptr), Present(nullptr), size(0) {}; 
	~List();
	void Add(data x);
	void Show();
	void next();
	void remove();
};
