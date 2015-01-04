//Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
//EXAMPLE Input: the node ‘c’ from the linked list a->b->c->d->e Result: nothing is returned, but the new linked list looks like a->b->d->e

#include <cstdio>
#include <cstddef>
#include "linkedlist.hpp"

void deleteNode(Node<int> *p) {
    Node<int> *next = p->next;
    p->next = next->next;
    p->value = next->value;
}

int main() {
    Node<int> *h1 = new Node<int>();
    InsertTail(h1, 3);
    InsertTail(h1, 1);
    InsertTail(h1, 5);
    InsertTail(h1, 9);
    InsertTail(h1, 9);
    PrintList(h1);

    Node<int> *p = h1->next->next->next;
    deleteNode(p);
    PrintList(h1);

    return 0;
}
