#pragma once
#ifndef SQLIST_H
#define SQLIST_H
template <typename T>
class SqList{
public:
	T* data;//顺序表存储空间基址
	int size;//表最大容量
	int end;//表尾元素下一位下标
	SqList(int _size);//构造函数, 为Data分配_size个元素大小的空间

	bool Empty();//判断表是否为空
	void Add(T data);//将元素加到顺序表尾
	void Print();//顺序输出顺序表
	int Length();//顺序表长度
	T Get(int n);//查找第n位元素
	void Delete(int n);//删除第n位元素
	void Insert(int n, T _data);//在第n位元素后插入_data
};
#endif
