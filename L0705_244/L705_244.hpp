#ifndef L0705_244_HPP
#define L0705_244_HPP

#include <vector>
#include <iostream>

struct EdgeNode {
    int y;
    int weight;
    EdgeNode* next;
};

struct Graph {
    int nvertices;
    int nedges;
    std::vector<EdgeNode*> edges;
    std::vector<int> degree;

    // Конструктор для инициализации графа
    Graph(int n);
    // Деструктор для освобождения памяти
    ~Graph();
};

void insert_edge(Graph* g, int x, int y, bool directed);
void print_graph(const Graph* g);

#endif
