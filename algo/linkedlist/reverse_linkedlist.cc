/* writing errors */
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

struct Node {
    Node *next;
    int v;
};

void insert_linkedlist(Node *root, Node *p) {
    if (root == NULL) return;
    while (root->next != NULL) root = root->next;
    root->next = p;
}

Node *reverse_linkedlist(Node *root) {
    if (root == NULL || root->next == NULL) return root;
    Node *a = root;
    Node *b = root->next;
    a->next = NULL;
    while (b != NULL) {
        Node *t = b->next;
        b->next = a;
        a = b;
        b = t;
    }
    return a;
}

void print_linkedlist(Node *root) {
    while (root != NULL) {
        printf("%d ", root->v);
        root = root->next;
    }
    printf("\n");
}

int main ()
{
    Node *root = new Node();
    root->v = 1;
    root->next = NULL;
    for (int i=2; i<9; ++i) {
        Node *p = new Node();
        p->v = i;
        p->next = NULL;
        insert_linkedlist(root, p);
    }
    print_linkedlist(root);
    root = reverse_linkedlist(root);
    print_linkedlist(root);
    return 0;
}
