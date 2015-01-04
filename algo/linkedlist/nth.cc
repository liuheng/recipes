//Implement an algorithm to find the nth to last element of a singly linked list.

#include <cassert>
#include "linkedlist.hpp"

using namespace std;

Node<int> *findNth(Node<int> *p, int N) {
    Node<int> *h1 = p->next;
    Node<int> *h2 = p->next;

    for (int i=N-1; i>0; --i) {
        if (h2 == NULL) {
            return NULL; 
        }
        h2 = h2->next;
    }
    while (h2->next != NULL) {
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1;
}

int main() {
    Node<int> *h1 = new Node<int>();
    for (int i=1; i<=20; ++i) {
        InsertTail(h1, i);
    }
    assert(16 == findNth(h1, 5)->value);
    return 0;
}
