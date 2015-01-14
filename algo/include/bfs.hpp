#include "graph.hpp"
#include "../queue/priorityqueue.hpp"

void bfs(Graph &g, Vertex &s) {
    // initialize
    for (int i=0; i<MAX_VERTEX_SIZE; ++i) {
        if (g.al[i] != NULL) {
            Node<Vertex> *p = g.al[i]->next;
            while (p != NULL) {
                p->d = POSITIVE_INFINITE;
                p->p = NIL;
            }
        } else {
            break;
        }
    }
    s.d = 0;
    s.p = NIL;
    PQueue<Vertex> Q;

    // running
    Q.Insert(s);
    while (!Q.IsEmpty()) {
    }


}
