
#include <iostream>
#include "LinkList.h"

template <typename T>
LinkList<T>::LinkList(){
	this->length = 0;
	this->head = NULL;
}

template <typename T>
LinkList<T>::~LinkList() {
	Node<T>* dlt = this->head;
	Node<T>* temp;
	while (dlt != NULL) {
		temp = dlt->next;
		delete dlt;
		dlt = temp;
	}
}

template <typename T>
bool LinkList<T>::Empty() {
	if (this->head == NULL) {
		return true;
	}
	return false;
}

template <typename T>
void LinkList<T>::Add(T _data) {
	Node<T>* temp = new Node<T>;
	temp->data = _data;
	temp->next = this->head;
	this->head = temp;
	++this->length;
}

template <typename T>
void LinkList<T>::Print() {
	Node<T>* temp = this->head;
	while (temp != NULL) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

template <typename T>
int LinkList<T>::Length() {
	return this->length;
}

template <typename T>
T LinkList<T>::Get(int n) {
	Node<T>* temp;
	temp = this->head;
	for (int i = 0; i < n - 1; ++i) {
		temp = temp->next;
	}
	return temp->data;
}

template <typename T>
void LinkList<T>::Delete(int n) {
	Node<T>* temp1;
	Node<T>* temp2;
	temp1 = this->head;
	for (int i = 0; i < n - 2; ++i) {
		temp1 = temp1->next;
	}
	temp2 = temp1->next;
	temp1->next = temp2->next;
	delete temp2;
}

template <typename T>
void LinkList<T>::Insert(int n, T _data) {
	Node<T>* temp1;
	temp1 = this->head;
	for (int i = 0; i < n - 1; ++i) {
		temp1 = temp1->next;
	}

	Node<T>* temp2 = new Node<T>;
	temp2->data = _data; temp2->next = temp1->next;
	temp1->next = temp2;
}
