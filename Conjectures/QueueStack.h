#pragma once

#include <iostream>
#include <string>
using namespace std;

template <class Type>
struct Node {
	Type data;
	Node<Type>* next;
};


template <class Type>
class QueueStack
{
public:
	QueueStack();

	void push(Type data);

	void pop();

	Type peek();

	bool isEmpty();

	friend ostream& operator << <>(ostream&, const Stack<Type>&);

private:
	Node<Type>* top;
};

template <class Type>
QueueStack<Type>::QueueStack() {
	top = nullptr;
}

template <class Type>
void QueueStack<Type>::push(Type data) {
	Node<Type>* toAdd = new Node<Type>;
	toAdd->data = data;
	toAdd->next = nullptr;
	if (top == nullptr) {
		top = toAdd;
		toAdd->next = nullptr;
	}
	else {
		toAdd->next = top;
		top = toAdd;
	}
}
template <class Type>
Type QueueStack<Type>::peek() {
	return top->data;
}
template <class Type>
void QueueStack<Type>::pop() {
	if (!isEmpty()) {
		Node<Type>* temp = top;
		top = top->next;
		delete temp;
	}
}
template <class Type>
bool QueueStack<Type>::isEmpty() {
	return (top == nullptr);

}