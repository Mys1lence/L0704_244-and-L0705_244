#ifndef L0704_244_HPP
#define L0704_244_HPP

#include <vector>

struct EdgeNode {
    int y;
    int weight;
    EdgeNode* next;
};

struct Graph {
    int nvertices;
    int nedges;
    bool directed;
    std::vector<EdgeNode*> edges;
    std::vector<int> degree;

    // Конструктор
    Graph(int n) : nvertices(n), nedges(0), edges(n, nullptr), degree(n, 0) {}
    ~Graph() {
        for (auto edge : edges) {
            while (edge) {
                EdgeNode* temp = edge;
                edge = edge->next;
                delete temp;
            }
        }
    }
};

// Объявление функции вставки ребра
void insert_edge(Graph* g, int x, int y, bool directed);

#endif // L0704_244_HPP
