//Describe how you could use a single array to implement three stacks.

#include "../linkedlist/linkedlist.hpp"
#include <cassert>

using namespace std;

#define MAX_STACK_SIZE (100)

class ThreeStack {
public:
    ThreeStack();
    bool Push(int idx, int value);
    int Pop(int idx);
    int Top(int idx);

private:
    Node<int> *stacks[3];
    Node<int> *freelist;
    Node<int> buf[MAX_STACK_SIZE];
};

ThreeStack::ThreeStack() {
    for (int i=MAX_STACK_SIZE-1; i>0; --i) {
        buf[i-1].next = &buf[i];
    }
    freelist = new Node<int>();
    freelist->next = &buf[0];
    for (int i=0; i<3; ++i) {
        stacks[i] = new Node<int>();
    }
}

bool ThreeStack::Push(int idx, int value) {
    if (idx > 2 || idx < 0 || freelist->next == NULL) {
        return false;
    }
    Node<int> *current = freelist->next;
    freelist->next = current->next;
    current->value = value;
    if (stacks[idx]->next != NULL) {
        current->next = stacks[idx]->next->next;
    }
    stacks[idx]->next = current;
    return true;
}

int ThreeStack::Pop(int idx) {
    if (idx > 2 || idx < 0 || stacks[idx]->next == NULL) {
        return -1;
    }
    Node<int> *current = stacks[idx]->next;
    stacks[idx] = stacks[idx]->next->next;
    return current->value;
}

int ThreeStack::Top(int idx) {
    if (idx > 2 || idx < 0 || stacks[idx]->next == NULL) {
        return -1;
    }
    Node<int> *current = stacks[idx]->next;
    return current->value;
}

int main() {
    ThreeStack s;
    s.Push(0, 3);
    s.Push(1, 3);
    s.Push(2, 9);
    s.Push(1, 4);
    s.Push(1, 6);
    s.Push(0, 1);
    assert(6 == s.Pop(1));
    s.Push(2, 2);
    assert(2 == s.Pop(2));
    return 0;
}
