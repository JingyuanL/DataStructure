#include <iostream>
#include "Stack.h"

int main() {
	Stack<int> s;
	if (s.Empty()) {
		for (int i = 0; i < 10; ++i) {
			s.Push(i + 1);
		}
	}
	s.Print();
	std::cout << s.Length() << std::endl;
	s.Pop();
	s.Print();
	return 0;
}
