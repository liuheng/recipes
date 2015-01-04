//implement a linkedlist
#include <cstddef>
#include <cstdio>

template <class T>
class Node {
public:
    Node()
        : next(NULL)
        , value(-1) {}
    Node *next;
    T value;
};

template <class T>
void InsertTail(Node<T> *head, const T &Elem) {
    Node<int> *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    Node<T> *node = new Node<T>();
    node->value = Elem;
    p->next = node;
}

template <class T>
void InsertTail(Node<T> *head, Node<T> *elem) {
    Node<int> *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = elem;
}

template <class T>
void PrintList(Node<T> *head) {
    Node<int> *p = head->next;
    while (p != NULL) {
        printf("%d -> ", p->value);
        p = p->next;
    }
    printf("NULL\n");
}
