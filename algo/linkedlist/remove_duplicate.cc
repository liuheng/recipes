//Write code to remove duplicates from an unsorted linked list.
//FOLLOW UP
//How would you solve this problem if a temporary buffer is not allowed?

#include <map>
#include "linkedlist.hpp"

using namespace std;

//不允许额外空间的O(n^2)解法忽略
void removeDuplicates(Node<int> *p) {
    Node<int> *h1 = p->next;
    map<int, bool> m;
    map<int, bool>::iterator it = m.end();
    if (h1 != NULL) {
        m[h1->value] = true;
    }
    Node<int> *h2 = h1->next;
    while (h2 != NULL) {
        it = m.find(h2->value);
        if (it == m.end()) {
            m[h2->value] = true;
            h2 = h2->next;
            h1 = h1->next;
        } else if (it->second) {
            h1->next = h2->next;
            delete h2;
            h2 = h1->next;
        }
    }
}

int main() {
    Node<int> *h1 = new Node<int>();
    InsertTail(h1, 3);
    InsertTail(h1, 3);
    InsertTail(h1, 5);
    InsertTail(h1, 9);
    InsertTail(h1, 9);
    InsertTail(h1, 8);
    PrintList(h1);
    removeDuplicates(h1);
    PrintList(h1);
}
