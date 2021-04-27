#include <iostream>
#include "Stack.h"

template <typename T>
Node<T>::Node(T _data) {
	this->data = _data;
	this->prior = NULL;
}

template <typename T>
Stack<T>::Stack() {
	this->Tail = NULL;
	this->length = 0;
}

template <typename T>
bool Stack<T>::Empty() {
	if (this->Tail == NULL) {
		return true;
	}
	return false;
}

template <typename T>
void Stack<T>::Push(T _data) {
	Node<T>* temp = new Node<T>(_data);
	temp->prior = this->Tail;
	this->Tail = temp;
	++this->length;
}

template <typename T>
void Stack<T>::Pop() {
	Node<T>* temp;
	temp = this->Tail;
	this->Tail = temp->prior;
	delete temp;
	--this->length;
}

template <typename T>
int Stack<T>::Length() {
	return this->length;
}

template <typename T>
void Stack<T>::Print() {
	Node<T>* temp;
	temp = this->Tail;
	while (temp != NULL) {
		std::cout << temp->data << " ";
		temp = temp->prior;
	}
	std::cout << std::endl;
}
