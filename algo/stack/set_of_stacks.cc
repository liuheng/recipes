//Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks, and should create a new stack once the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack (that is, pop() should return the same values as it would if there were just a single stack). FOLLOW UP Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.

#include <cassert>
#define MAX_STACK_SIZE 3
#include "stack.hpp"

#define STACK_NUM 10

using namespace std;


class SetOfStacks {
public:
    SetOfStacks() : current(0) {}
    int Push(int value) {
        if (current >= STACK_NUM) {
            return -1;
        }
        if (stacks[current].IsFull()) {
            if (current + 1 >= STACK_NUM) {
                return -1;
            } else {
                ++ current;
            }
        }
        stacks[current].Push(value);
        return 0;
    }
    int Pop() {
        if (stacks[current].IsEmpty()) {
            if (current - 1 < 0) {
                return -1;
            } else {
                -- current;
            }
        }
        return stacks[current].Pop();
    }
    int Top() {
        if (stacks[current].IsEmpty()) {
            if (current - 1 < 0) {
                return -1;
            } else {
                -- current;
            }
        }
        return stacks[current].Top();
    }
    bool IsEmpty() {
        return current == 0 && stacks[current].IsEmpty();
    }
    int IsFull() {
        return current == STACK_NUM - 1 && stacks[current].IsFull();
    }
private:
    Stack<int> stacks[STACK_NUM];
    size_t current;
};

int main () {
    SetOfStacks s;
    assert(s.IsEmpty() == true);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    assert(s.Top() == 3);
    s.Push(4);
    assert(s.Top() == 4);
    s.Push(5);
    assert(s.Top() == 5);
    s.Push(6);
    s.Push(7);
    s.Push(8);
    assert(s.Pop() == 8);
    assert(s.Pop() == 7);
    assert(s.Top() == 6);
    assert(s.Pop() == 6);
    assert(s.Top() == 5);
    assert(s.Pop() == 5);
    assert(s.Pop() == 4);
    assert(s.IsFull() == false);
    assert(s.IsEmpty() == false);
    return 0;
}
