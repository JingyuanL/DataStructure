#pragma once
#ifndef QUENE_H
#define QUENE_H
/*链队*/
template <typename T>
struct Node {
	T data;
	Node<T>* next;
};

template <typename T>
class Quene{
public:
	Quene();
	bool Empty();
	void EnQuene(T _data);
	void DeQuene();
	int Length();
	void Print();
private:
	int length;
	Node<T>* head;
	Node<T>* tail;
};
#endif



