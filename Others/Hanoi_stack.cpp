#include <iostream>

using namespace std;

struct hni{
    int status;
    int n;
    char a;
    char b;
    char c;
};

struct stack{
    hni p;
    struct stack *next;
};

void pop(stack* stk);
void push(hni h, stack* stk);
bool empty(stack* stk);
void move(int n, char a, char b);
hni& GetTop(stack* stk);

int main(){
    int n;
    cin >> n;

    stack* stk = new stack;
    stk->next = NULL;
    
    hni first;
    first.status = 0; first.n = n;
    first.a = 'x'; first.b = 'y'; first.c = 'z';
    
    push(first, stk);

    while(!empty(stk)){
        hni& top = GetTop(stk);
        if(top.n == 1){
            move(top.n, top.a, top.c);
            pop(stk);
            continue;
        }
        else{
            if(top.status == 0){
                top.status = 1;
                hni temp;//temp.n == top.n-1, status = 1
                temp.n = (top.n) - 1; temp.status = 0;
                temp.a = top.a; temp.b = top.c; temp.c = top.b;
                push(temp, stk);
                continue;
            }
            else if(top.status == 1){
                move(top.n, top.a, top.c);//status = 2
                top.status = 2;
                continue;
            }
            else if(top.status == 2){
                hni temp;//temp.n == top.n-1, status = 3;
                temp.n = (top.n) - 1; temp.status = 0;
                temp.a = top.b; temp.b = top.a; temp.c = top.c;
                push(temp, stk);
                top.status = 3;
                continue;
            }
            else if(top.status == 3){
                pop(stk);
                continue;
            }
        }
    }
    return 0;
}

void pop(stack* stk){
    stack* temp;
    temp = stk->next;
    stk->next = temp->next;
    delete temp;
}
void push(hni h, stack* stk){
    stack* temp;
    temp = new stack;
    temp->p = h;
    temp->next = stk->next;
    stk->next = temp;
}
bool empty(stack* stk){
    if(stk->next == NULL){
        return true;
    }
    return false;
}
hni& GetTop(stack* stk){
    return stk->next->p;
}
void move(int n, char a, char b){
    cout << n << " from " << a << " to " << b << endl;
}
