#include "graph.hpp"
#include <cstdlib>
#include <string>
#include <fstream>

#define MAX_LINE_SIZE 100

using namespace std;


void UndirectedGraph::AddEdge(const Edge &e) {
    E++;
    bool f_found = false;
    bool t_found = false;
    int i = 0;
    for (; i < MAX_VERTEX_SIZE; ++i) {
        if (al[i] == NULL) {
            break;
        }
        if (al[i]->value.v == e.f) { // 这里不检查边是否已经存在，允许多重边
            Node<Vertex> *node = new Node<Vertex>();
            node->value.v = e.t;
            node->value.w = e.w;
            node->next = al[i]->next;
            al[i]->next = node;
            f_found = true;
        } else if (al[i]->value.v == e.t) {
            Node<Vertex> *node = new Node<Vertex>();
            node->value.v = e.f;
            node->value.w = e.w;
            node->next = al[i]->next;
            al[i]->next = node;
            t_found = true;
        }
    }
    if (!f_found && i<MAX_VERTEX_SIZE) {
        Node<Vertex> *node = new Node<Vertex>();
        node->value.v = e.f;
        al[i] = node;
        node = new Node<Vertex>();
        node->value.v = e.t;
        node->value.w = e.w;
        node->next = al[i]->next;
        al[i]->next = node;
        V++;
        i++;
    }
    if (!t_found && i<MAX_VERTEX_SIZE) {
        Node<Vertex> *node = new Node<Vertex>();
        node->value.v = e.t;
        al[i] = node;
        node = new Node<Vertex>();
        node->value.v = e.f;
        node->value.w = e.w;
        node->next = al[i]->next;
        al[i]->next = node;
        V++;
        i++;
    }
}

Node<Vertex> *UndirectedGraph::Adj(const char v) {
    for (int i = 0; i < MAX_VERTEX_SIZE; ++i) {
        if (al[i] == NULL) {
            return NULL;
        }
        if (al[i]->value.v == v) {
            return al[i]->next;
        }
    }
}

void UndirectedGraph::Print() {
    printf("number of vertices: %d\n", V);
    printf("number of edges: %d\n", E);
    for (int i=0; i<MAX_VERTEX_SIZE; ++i) {
        if (al[i] == NULL) {
            break;
        } else {
            printf("|%c| -> ", al[i]->value.v, al[i]->value.w);
            Node<Vertex> *p = al[i]->next;
            while (p != NULL) {
                printf("%c[%d] -> ", p->value.v, p->value.w);
                p = p->next;
            }
            printf("NULL\n");
        }
    }
}

///////////////////////////////////////////////////////////////

void DirectedGraph::AddEdge(const Edge &e) {
    E++;
    bool f_found = false;
    int i = 0;
    for (; i < MAX_VERTEX_SIZE; ++i) {
        if (al[i] == NULL) {
            break;
        }
        if (al[i]->value.v == e.f) {
            Node<Vertex> *node = new Node<Vertex>();
            node->value.v = e.t;
            node->value.w = e.w;
            node->next = al[i]->next;
            al[i]->next = node;
            f_found = true;
        }
    }
    if (!f_found && i<MAX_VERTEX_SIZE) {
        Node<Vertex> *node = new Node<Vertex>();
        node->value.v = e.f;
        al[i] = node;
        node = new Node<Vertex>();
        node->value.v = e.t;
        node->value.w = e.w;
        node->next = al[i]->next;
        al[i]->next = node;
        V++;
        i++;
    }
}

Node<Vertex> *DirectedGraph::Adj(const char v) {
    for (int i = 0; i < MAX_VERTEX_SIZE; ++i) {
        if (al[i] == NULL) {
            return NULL;
        }
        if (al[i]->value.v == v) {
            return al[i]->next;
        }
    }
}

DirectedGraph *DirectedGraph::Reverse() {
    DirectedGraph *g = new DirectedGraph();
    for (int i=0; i<MAX_VERTEX_SIZE; ++i) {
        if (al[i] == NULL) {
            break;
        } else {
            Node<Vertex> *p = al[i]->next;
            while (p != NULL) {
                Edge e(p->value.v, al[i]->value.v, p->value.w);
                g->AddEdge(e);
                p = p->next;
            }
        }
    }
    return g;
}

void DirectedGraph::Print() {
    printf("number of vertices: %d\n", V);
    printf("number of edges: %d\n", E);
    for (int i=0; i<MAX_VERTEX_SIZE; ++i) {
        if (al[i] == NULL) {
            break;
        } else {
            printf("|%c| -> ", al[i]->value.v, al[i]->value.w);
            Node<Vertex> *p = al[i]->next;
            while (p != NULL) {
                printf("%c[%d] -> ", p->value.v, p->value.w);
                p = p->next;
            }
            printf("NULL\n");
        }
    }
}

///////////////////////////////////////////////////////////////

void UndirectedGraph_AM::AddEdge(const Edge &e) {
    if (e.f < 'a' || e.f > 'z' || e.t < 'a' || e.t > 'z') {
        return;
    } else if (am[e.f - 'a'][e.t - 'a'] == 0) {
        am[e.f - 'a'][e.t - 'a'] = e.w;
        V++;
        E++;
    }
}

Node<Vertex> *UndirectedGraph_AM::Adj(const char v) {
    Node<Vertex> *head = NULL;
    for (int j=0; j<MAX_VERTEX_SIZE; ++j) {
        if (am[v - 'a'][j] != 0) {
            Node<Vertex> *node = new Node<Vertex>();
            node->value.v = j + 'a';
            node->value.w = am[v - 'a'][j];
            if (head == NULL) {
                head = node;
            } else {
                node->next = head;
                head = node;
            }
        }
    }
    return head;
}

void UndirectedGraph_AM::Print() {
    printf("  ");
    for (int m=0; m<MAX_VERTEX_SIZE; ++m) {
        printf("%c ", m+'a');
    }
    printf("\n");
    for (int i=0; i<MAX_VERTEX_SIZE; ++i) {
        printf("%c ", i+'a');
        for (int j=0; j<MAX_VERTEX_SIZE; ++j) {
            printf("%d ", am[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

///////////////////////////////////////////////////////////////

void DirectedGraph_AM::AddEdge(const Edge &e) {
    if (e.f < 'a' || e.f > 'z' || e.t < 'a' || e.t > 'z') {
        return;
    } else if (am[e.f - 'a'][e.t - 'a'] == 0) {
        am[e.f - 'a'][e.t - 'a'] = e.w;
        V++;
        E++;
    }
}

Node<Vertex> *DirectedGraph_AM::Adj(const char v) {
    Node<Vertex> *head = NULL;
    for (int j=0; j<MAX_VERTEX_SIZE; ++j) {
        if (am[v - 'a'][j] != 0) {
            Node<Vertex> *node = new Node<Vertex>();
            node->value.v = j + 'a';
            node->value.w = am[v - 'a'][j];
            if (head == NULL) {
                head = node;
            } else {
                node->next = head;
                head = node;
            }
        }
    }
    return head;
}

DirectedGraph_AM *DirectedGraph_AM::Reverse() {
    DirectedGraph_AM *g = new DirectedGraph_AM();
    memcpy(g->am, am, sizeof(am));
    for (int i=0; i<MAX_VERTEX_SIZE; ++i) {
        for (int j=i+1; j<MAX_VERTEX_SIZE; ++j) {
            g->am[i][j] = g->am[i][j] ^ g->am[j][i];
            g->am[j][i] = g->am[i][j] ^ g->am[j][i];
            g->am[i][j] = g->am[i][j] ^ g->am[j][i];
        }
    }
    return g;
}

void DirectedGraph_AM::Print() {
    printf("  ");
    for (int m=0; m<MAX_VERTEX_SIZE; ++m) {
        printf("%c ", m+'a');
    }
    printf("\n");
    for (int i=0; i<MAX_VERTEX_SIZE; ++i) {
        printf("%c ", i+'a');
        for (int j=0; j<MAX_VERTEX_SIZE; ++j) {
            printf("%d ", am[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

///////////////////////////////////////////////////////////////

void BuildGraph(const char *filename, Graph *graph) {
    ifstream ifs(filename);
    string s1, s2, s3;
    printf("input graph:\n");
    while (ifs >> s1 >> s2 >> s3) {
        printf("%s %s %s\n", s1.c_str(), s2.c_str(), s3.c_str());
        Edge e(s1.at(0), s2.at(0), atoi(s3.c_str()));
        graph->AddEdge(e);
    }
    ifs.close();
    graph->Print();
}
