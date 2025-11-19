#include "L0705_244.hpp"
#include <iostream>

graph::graph(int n, bool dir) 
    : nvertices(n), nedges(0), directed(dir), edges(n + 1), degree(n + 1, 0) {
    // Индексы от 1 до n (как в оригинальном коде)
}

void graph::insert_edge(int x, int y, bool directed, int weight) {
    // Создание нового ребра
    auto new_edge = std::make_unique<edgenode>(y, weight);
    new_edge->next = std::move(edges[x]);
    edges[x] = std::move(new_edge);
    degree[x]++;
    nedges++;
    
    // Для неориентированного графа добавляем обратное ребро
    if (!directed) {
        insert_edge(y, x, true, weight);
    }
}

void graph::print_graph() const {
    std::cout << "Граф (" << (directed ? "ориентированный" : "неориентированный") 
              << "): " << nvertices << " вершин, " << nedges << " ребер\n";
    
    for (int i = 1; i <= nvertices; i++) {
        std::cout << i << ": ";
        edgenode* p = edges[i].get();
        
        while (p != nullptr) {
            std::cout << " " << p->y;
            p = p->next.get();
        }
        std::cout << std::endl;
    }
}
