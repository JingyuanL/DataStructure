#include <iostream>
#include "Quene.h"

template <typename T>
Quene<T>::Quene() {
	this->head = NULL;
	this->tail = NULL;
	this->length = 0;
}

template <typename T>
bool Quene<T>::Empty() {
	if (this->head == NULL) {
		return true;
	}
	return false;
}

template <typename T>
void Quene<T>::EnQuene(T _data) {
	Node<T>* temp = new Node<T>;
	temp->data = _data;
	temp->next = NULL;
	if (this->head == NULL) {
		this->head = temp;
	}
	else {
		this->tail->next = temp;
	}
	this->tail = temp;
	++this->length;
}

template <typename T>
void Quene<T>::DeQuene() {
	Node<T>* temp = this->head;
	this->head = temp->next;
	if (this->tail == temp) {
		this->tail = NULL;
	}
	delete temp;
	--this->length;
}

template <typename T>
int Quene<T>::Length() {
	return this->length;
}

template <typename T>
void Quene<T>::Print() {
	Node<T>* temp;
	temp = this->head;
	while (temp != NULL) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}
