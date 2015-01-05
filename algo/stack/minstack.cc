//How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element? Push, pop and min should all operate in O(1) time.

#include "stack.hpp"
#include <cassert>

using namespace std;

class MinStack {
public:
    bool push(int a);
    int pop();
    int min();

private:
    Stack<int> m_s1;
    Stack<int> m_s2;
};

bool MinStack::push(int a) {
    if (m_s2.Top() == -1 || a < m_s2.Top()) {
        m_s2.Push(a);
    }
    return m_s1.Push(a);
}

int MinStack::pop() {
    int a = m_s1.Pop();
    if (a == m_s2.Top()) {
        m_s2.Pop();
    }
    return a;
}

int MinStack::min() {
    return m_s2.Top();
}

int main() {
    MinStack ms;
    ms.push(3);
    ms.push(9);
    assert(3 == ms.min());
    ms.push(1);
    assert(1 == ms.min());
    assert(1 == ms.pop());
    ms.push(2);
    assert(2 == ms.min());
    assert(2 == ms.pop());
    ms.push(7);
    assert(3 == ms.min());
    return 0;
}
