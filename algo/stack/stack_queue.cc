//Implement a MyQueue class which implements a queue using two stacks.

#include <cassert>
#include "stack.hpp"

using namespace std;

class MyQueue {
public:
    MyQueue() : m_len(0) {}
    int Enqueue(int value) {
        if (m_len >= MAX_STACK_SIZE) {
            return -1;
        } else {
            m_s1.Push(value);
            return 0;
        }
    }

    int Dequeue() {
        if (m_s2.IsEmpty()) {
            while(true) {
                int a = m_s1.Pop();
                if (a == -1) {
                    break;
                } else {
                    m_s2.Push(a);
                }
            }
        }
        return m_s2.Pop();
    }

    int Front() {
        if (m_s2.IsEmpty()) {
            while(true) {
                int a = m_s1.Pop();
                if (a == -1) {
                    break;
                } else {
                    m_s2.Push(a);
                }
            }
        }
        return m_s2.Top();
    }

    int Back() {
        if (m_s1.IsEmpty() && !m_s2.IsEmpty()) {
            while(true) {
                int a = m_s2.Pop();
                if (a == -1) {
                    break;
                } else {
                    m_s1.Push(a);
                }
            }
        }
        return m_s1.Top();
    }

private:
    Stack<int> m_s1;
    Stack<int> m_s2;
    size_t m_len;
};

int main() {
    MyQueue q;
    assert(0 == q.Enqueue(1));
    assert(0 == q.Enqueue(2));
    assert(0 == q.Enqueue(3));
    assert(0 == q.Enqueue(4));
    assert(0 == q.Enqueue(5));

    assert(1 == q.Dequeue());
    assert(2 == q.Dequeue());

    assert(3 == q.Front());
    assert(5 == q.Back());
    assert(0 == q.Enqueue(6));

    assert(3 == q.Front());
    assert(3 == q.Dequeue());
    assert(4 == q.Dequeue());
    assert(0 == q.Enqueue(7));

    assert(7 == q.Back());

    return 0;
}
