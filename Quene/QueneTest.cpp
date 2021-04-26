#include <iostream>
#include "Quene.cpp"

int main() {
	Quene<int> q;
	if (q.Empty()) {
		for (int i = 0; i < 5; ++i) {
			q.EnQuene(i);
		}
	}
	q.Print();
	q.DeQuene();
	q.Print();
	std::cout << q.Length() << std::endl;
	return 0;
}
