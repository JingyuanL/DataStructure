#include <iostream>
#include "SqList.h"
using std::cout;
using std::endl;
int main() {
	SqList<int> Head(15);
	if (Head.Empty()) {
		for (int i = 0; i < 10; ++i) {
			Head.Add(i);
		}
	}
	Head.Print();
	cout << "第三位：" << Head.Get(3) << endl;
	Head.Delete(5);
	cout << "当前长度:" << Head.Length() << endl;
	Head.Print();
	Head.Insert(4, 4);
	cout << "当前长度:" << Head.Length() << endl;
	Head.Print();
	return 0;
}
