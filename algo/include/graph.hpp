#ifndef _GRAPH_H
#define _GRAPH_H

#include <cstring>
#include "../linkedlist/linkedlist.hpp"

#define MAX_VERTEX_SIZE 26
#define POSITIVE_INFINITE ((1 << (sizeof(int) * 8 - 1)) - 1)
#define NIL '-'

using namespace std;

struct Vertex {
    int p; // 算法运行过程中的parent域
    int d; // 算法运行过程中的distance域
    int f; // 算法运行过程中的finish域
    int w; // 边(u, v)的权值存在顶点u的邻接表的v中
    int c; // 顶点的颜色域, 0为白色，1为灰色，2为黑色
    char v; // 节点卫星数据，以字母代替

    Vertex() : v('-'), p(NIL), d(POSITIVE_INFINITE), f(POSITIVE_INFINITE), w(POSITIVE_INFINITE), c(0) {}
    Vertex(char v_, int w_) : v(v_), p(NIL), d(POSITIVE_INFINITE), f(POSITIVE_INFINITE), w(POSITIVE_INFINITE), c(0) {}
    bool operator==(struct Vertex &v1, struct Vertex &v2) {
        return v1.v == v2.v;
    }
};

struct Edge {
    int w; // 边的权值
    char f; // 边的起点
    char t; // 边的终点

    Edge() : f('-'), t('-'), w(-1) {}
    Edge(char f_, char t_, int w_) : f(f_), t(t_), w(w_) {}
};

struct Graph {
    virtual void AddEdge(const Edge &e) = 0; // 添加无向边
    virtual Node<Vertex> *Adj(const char v) = 0; //获得顶点v的邻接点链表
    virtual void Print() = 0; // 友好的打印自己
};

///////////////////////////////////////////////////////////////

struct UndirectedGraph : public Graph {
    int V; // 节点数
    int E; // 边数
    Node<Vertex> *al[MAX_VERTEX_SIZE]; // 邻接表

    virtual void AddEdge(const Edge &e); // 添加无向边
    virtual Node<Vertex> *Adj(const char v); //获得顶点v的邻接点链表
    virtual void Print(); // 友好的打印自己

    UndirectedGraph() : V(0), E(0) {
        memset(al, 0, sizeof(al));
    }
};

///////////////////////////////////////////////////////////////

struct DirectedGraph : public Graph {
    int V; // 节点数
    int E; // 边数
    Node<Vertex> *al[MAX_VERTEX_SIZE]; // 邻接表

    virtual void AddEdge(const Edge &e); // 添加有向边
    virtual Node<Vertex> *Adj(const char v); // 获得顶点v的邻接点链表
    virtual void Print(); // 友好的打印自己

    DirectedGraph *Reverse(); // 翻转图
    DirectedGraph() : V(0), E(0) {
        memset(al, 0, sizeof(al));
    }
};

///////////////////////////////////////////////////////////////

struct UndirectedGraph_AM : public Graph {
    int V; // 节点数
    int E; // 边数
    int am[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE]; // 邻接表, 存放权值

    virtual void AddEdge(const Edge &e); // 添加边
    virtual Node<Vertex> *Adj(const char v); //获得顶点v的邻接点链表
    virtual void Print(); // 友好的打印自己

    UndirectedGraph_AM() : V(0), E(0) {
        memset(am, 0, sizeof(am));
    }
};


///////////////////////////////////////////////////////////////

struct DirectedGraph_AM : public Graph {
    int V; // 节点数
    int E; // 边数
    int am[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE]; // 邻接表, 存放权值

    virtual void AddEdge(const Edge &e); // 添加有向边
    virtual Node<Vertex> *Adj(const char v); // 获得顶点v的邻接点链表
    virtual void Print(); // 友好的打印自己

    DirectedGraph_AM *Reverse(); // 翻转图
    DirectedGraph_AM() : V(0), E(0) {
        memset(am, 0, sizeof(am));
    }
};

///////////////////////////////////////////////////////////////

// build specific graph from a file
void BuildGraph(const char *filename, Graph *graph);

#endif
