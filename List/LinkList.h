#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H

template <typename T>
struct Node {
	T data;
	Node<T>* next;
};

template <typename T>
class LinkList {
private:
	int length;
	Node<T>* head;
public:
	LinkList();
	~LinkList();
	bool Empty();//判断表是否为空
	void Add(T _data);//头插
	void Print();//输出链表
	int Length();//顺序表长度
	T Get(int n);//查找第n位元素
	void Delete(int n);//删除第n位元素
	void Insert(int n, T _data);//在第n位元素后插入_data
};
#endif
