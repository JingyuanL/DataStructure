#include <iostream>
#include "LinkList.cpp"

int main() {
	LinkList<int> Head;
	if (Head.Empty()) {
		for (int i = 0; i < 5; ++i) {
			Head.Add(i);
		}
	}
	std::cout << Head.Length() << std::endl;
	Head.Print();
	std::cout << Head.Get(3) << std::endl;
	Head.Delete(3);
	Head.Print();
	Head.Insert(2, 2);
	Head.Print();
	return 0;
}
