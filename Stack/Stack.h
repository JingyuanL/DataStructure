#pragma once
#ifndef STACK_H
#define STACK_H

template <typename T>
struct Node {
	T data;
	Node<T>* prior;
	Node(T _data);
};

template <typename T>
class Stack {
public:
	Stack();
	bool Empty();
	void Push(T _data);
	void Pop();
	int Length();
	void Print();
private:
	int length;
	Node<T>* Tail;
};
#endif
