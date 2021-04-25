#include <iostream>
#include "SqList.h"

template <typename T>
SqList<T>::SqList(int _size) {
	this->end = 0;
	this->size = _size;
	this->data = new T[size];
}

template <typename T>
void SqList<T>::Add(T _data) {
	this->data[this->end] = _data;
	++this->end;
}

template <typename T>
void SqList<T>::Print(){
	for (int i = 0; i < end; ++i) {
		std::cout << this->data[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
bool SqList<T>::Empty() {
	if (this->end == 0) {
		return true;
	}
	return false;
}

template <typename T>
int SqList<T>::Length() {
	return this->end;
}

template <typename T>
T SqList<T>::Get(int n) {
	return this->data[n - 1];
}

template <typename T>
void SqList<T>::Delete(int n) {
	for (int i = n; i < this->end; ++i) {
		this->data[i - 1] = this->data[i];
	}
	--this->end;
}

template <typename T>
void SqList<T>::Insert(int n, T _data) {
	for (int i = this->end; i > n; --i) {
		this->data[i] = this->data[i - 1];
	}
	++this->end;
	this->data[n] = _data;
}
