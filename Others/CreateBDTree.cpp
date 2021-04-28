#include <iostream>
#include <string>

using namespace std;

struct TNode{
	char data;
	TNode* lchild;
	TNode* rchild;
	TNode();
};
TNode::TNode() {
	this->lchild = NULL;
	this->rchild = NULL;
	this->data = ' ';
}

struct SNode {
	TNode* data;
	SNode* prior;
};

class Stack {
public:
	Stack();
	void Pop();
	TNode* Top();
	void Push(TNode* _data);
private:
	SNode* Tail;
};

Stack::Stack() {
	this->Tail = NULL;
}
void Stack::Pop() {
	SNode* temp = this->Tail;
	if (temp == NULL)
		this->Tail = NULL;
	else
		this->Tail = temp->prior;
	delete temp;
}
TNode* Stack::Top() {
	if (this->Tail != NULL)
		return this->Tail->data;
	else
		return NULL;
}
void Stack::Push(TNode* _data) {
	SNode* temp = new SNode;
	temp->prior = this->Tail;
	temp->data = _data;
	this->Tail = temp;
}

class BDTree {
public:
	BDTree(string s);
	TNode* Head;
};

BDTree::BDTree(string s) {
	cout << "括号表示法二叉树:" << s << endl;
	TNode* domin;
	TNode* first = new TNode;
	this->Head = first;
	Stack dominstk;
	domin = first;
	dominstk.Push(first);
	int len = s.length();
	bool left = true;
	for (int i = 1; i < len; ++i) {
		if (s[i] == '(') {
			left = true;
		}
		else if (s[i] == ',') {
			left = false;
		}
		else if (s[i] == ')') {
			dominstk.Pop();
			domin = dominstk.Top();
		}
		else {
			TNode* temp = new TNode;
			temp->data = s[i];
			if (left) {
				domin->lchild = temp;
			}
			else {
				domin->rchild = temp;
			}
			if (s[i + 1] == '(') {
				dominstk.Push(temp);
				domin = dominstk.Top();
			}
		}
	}
}

//中序遍历输出
void Print(TNode* a) {
	if (a->lchild != NULL)
		Print(a->lchild);
	cout << a->data << " ";
	if (a->rchild != NULL)
		Print(a->rchild);
}

int main() {
	string s = "(A(B(C,),D(,E)))";
	BDTree h(s);
	//cin >> s;
	cout << "中序遍历二叉树:" << endl;
	Print(h.Head->lchild);
	return 0;
}
