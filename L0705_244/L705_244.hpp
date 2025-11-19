#ifndef L0705_244_HPP
#define L0705_244_HPP

#include <vector>
#include <iostream>
#include <memory>

struct edgenode {
    int y;                    // Вершина, в которую ведет ребро
    int weight;               // Вес ребра
    std::unique_ptr<edgenode> next;  // Следующее ребро в списке
    
    edgenode(int vertex, int w = 0) : y(vertex), weight(w), next(nullptr) {}
};

struct graph {
    int nvertices;           // Количество вершин
    int nedges;              // Количество ребер
    bool directed;           // Ориентированный ли граф
    std::vector<std::unique_ptr<edgenode>> edges;  // Массив списков смежности
    std::vector<int> degree; // Степени вершин

    // Конструктор
    graph(int n, bool dir = false);
    
    // Основные методы
    void insert_edge(int x, int y, bool directed, int weight = 0);
    void print_graph() const;
};

#endif // L0705_244_HPP
