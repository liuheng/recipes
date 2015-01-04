//You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1’s digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list. EXAMPLE Input: (3 -> 1 -> 5) + (5 -> 9 -> 2) Output: 8 -> 0 -> 8

#include <cassert>
#include <cstddef>
#include <cstdio>
#include "linkedlist.hpp"

Node<int> *addList(Node<int> *n1, Node<int> *n2) {
    Node<int> *h1 = n1->next;
    Node<int> *h2 = n2->next;
    Node<int> *head = new Node<int>();
    Node<int> *h3 = head;
    Node<int> *h4 = NULL;
    int sum = 0;
    int base = 0;
    bool carry = false;
    while (h1 != NULL && h2 != NULL) {
        sum = h1->value + h2->value + (carry ? 1 : 0);
        base = sum % 10;
        carry = sum / 10 == 1;
        Node<int> *node = new Node<int>();
        node->value = base;
        h3->next = node;
        h1 = h1->next;
        h2 = h2->next;
        h3 = h3->next;
    }
    if (h1 == NULL && h2 == NULL) {
        if (carry) {
            Node<int> *node = new Node<int>();
            node->value = 1;
            h3->next = node;
        }
    } else {
        if (h1 != NULL) {
            h4 = h1;
        } else {
            h4 = h2;
        }
        while (carry && h4 != NULL) {
            sum = h4->value + carry;
            base = sum % 10;
            carry = sum / 10 == 1;
            Node<int> *node = new Node<int>();
            node->value = base;
            h3->next = node;
            h3 = h3->next;
            h4 = h4->next;
        }
        if (carry) {
            Node<int> *node = new Node<int>();
            node->value = 1;
            h3->next = node;
        }
    }
    return head;
}

// ignore memory clean, should be done by caller properly
int main() {
    Node<int> *h1 = new Node<int>();
    InsertTail(h1, 3);
    InsertTail(h1, 1);
    InsertTail(h1, 5);
    InsertTail(h1, 9);
    InsertTail(h1, 9);

    Node<int> *h2 = new Node<int>();
    InsertTail(h2, 8);
    InsertTail(h2, 8);
    InsertTail(h2, 6);

    PrintList(h1);
    PrintList(h2);

    Node<int> *h3 = addList(h1, h2);
    PrintList(h3);

    return 0;
}
