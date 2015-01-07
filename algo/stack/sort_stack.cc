//Write a program to sort a stack in ascending order. You should not make any assump- tions about how the stack is implemented. The following are the only functions that should be used to write this program: push | pop | peek | isEmpty.

#include <cassert>
#include <iostream>
#include "stack.hpp"

using namespace std;

void PrintStack(Stack<int> &s) {
    Stack<int> as;
    while (!s.IsEmpty()) {
        as.Push(s.Top());
        cout<<s.Pop()<<"-";
    }
    cout<<endl;
    while (!as.IsEmpty()) {
        s.Push(as.Pop());
    }
}

void SortStack(Stack<int> & s) {
    Stack<int> as;
    while (!s.IsEmpty()) {
        int v = s.Pop();
        if (as.IsEmpty() || as.Top() <= v) {
            as.Push(v);
        } else {
            while (!as.IsEmpty() && as.Top() > v) {
                int av = as.Pop();
                s.Push(av);
            }
            as.Push(v);
        }
    }
    while (!as.IsEmpty()) {
        s.Push(as.Pop());
    }
}

int main() {
    Stack<int> s;
    s.Push(2);
    s.Push(3);
    s.Push(5);
    s.Push(8);
    s.Push(3);
    s.Push(1);
    s.Push(7);
    s.Push(4);

    PrintStack(s);
    SortStack(s);
    PrintStack(s);

    return 0;
}
