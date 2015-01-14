#include "graph.hpp"

int main() {
    int num = POSITIVE_INFINITE;
    printf("%d\n", num);
    UndirectedGraph g1;
    BuildGraph("graph.txt", &g1);
    Node<Vertex> *adj1 = g1.Adj('b');
    printf("adjacent vertices of 'b':\n");
    while (adj1 != NULL) {
        printf("%c[%d] ", adj1->value.v, adj1->value.w);
        adj1 = adj1->next;
    }
    printf("\n");

    DirectedGraph g2;
    BuildGraph("graph.txt", &g2);
    Node<Vertex> *adj2 = g2.Adj('b');
    printf("adjacent vertices of 'b':\n");
    while (adj2 != NULL) {
        printf("%c[%d] ", adj2->value.v, adj2->value.w);
        adj2 = adj2->next;
    }
    printf("\n");
    DirectedGraph *g3 = g2.Reverse();
    g3->Print();

    UndirectedGraph_AM g4;
    BuildGraph("graph.txt", &g4);
    Node<Vertex> *adj4 = g4.Adj('b');
    printf("adjacent vertices of 'b':\n");
    while (adj4 != NULL) {
        printf("%c[%d] ", adj4->value.v, adj4->value.w);
        adj4 = adj4->next;
    }
    printf("\n");

    DirectedGraph_AM g5;
    BuildGraph("graph.txt", &g5);
    Node<Vertex> *adj5 = g5.Adj('b');
    printf("adjacent vertices of 'b':\n");
    while (adj5 != NULL) {
        printf("%c[%d] ", adj5->value.v, adj5->value.w);
        adj5 = adj5->next;
    }
    printf("\n");
    DirectedGraph_AM *g6 = g5.Reverse();
    g6->Print();
    return 0;
}
