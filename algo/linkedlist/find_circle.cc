//Given a circular linked list, implement an algorithm which returns node at the beginning of the loop. DEFINITION Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list. EXAMPLE input: A -> B -> C -> D -> E -> C (the same C as earlier) output: C

#include <cstdio>
#include <cstddef>
#include <cassert>
#include "linkedlist.hpp"

using namespace std;

Node<int> *findCircle(Node<int> *p) {
    Node<int> *h1 = p->next;
    Node<int> *h2 = p->next;
    do {
        h1 = h1->next;
        h2 = h2->next;
        h2 = h2->next;
    } while(h1 != h2);

    Node<int> *h3 = p->next;
    do {
        h3 = h3->next;
        h1 = h1->next;
    } while (h1 != h3);

    return h1;
}

int main() {
    Node<int> *h1 = new Node<int>();
    InsertTail(h1, 1);
    InsertTail(h1, 2);
    InsertTail(h1, 3);
    Node<int> *p4 = new Node<int>();
    p4->value = 4;
    InsertTail(h1, p4);
    InsertTail(h1, 5);
    InsertTail(h1, 6);
    InsertTail(h1, 7);
    InsertTail(h1, p4);

    assert(4 == findCircle(h1)->value);
    return 0;
}
