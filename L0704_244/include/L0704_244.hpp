#ifndef L0704_244_HPP
#define L0704_244_HPP

#include <vector>
#include <iostream>
#include <memory>

struct EdgeNode {
    int y;              // Вершина, в которую ведет ребро
    int weight;         // Вес ребра
    std::unique_ptr<EdgeNode> next;     // Следующее ребро в списке
    
    EdgeNode(int vertex, int w = 0) : y(vertex), weight(w), next(nullptr) {}
};

class Graph {
private:
    int nvertices;                      // Количество вершин
    int nedges;                         // Количество ребер
    bool directed;                      // Ориентированный ли граф
    std::vector<std::unique_ptr<EdgeNode>> edges;  // Массив списков смежности
    std::vector<int> degree;            // Степени вершин

public:
    // Конструкторы
    Graph(int n, bool dir = false);
    ~Graph() = default; // Деструктор больше не нужен благодаря unique_ptr
    
    // Запрет копирования
    Graph(const Graph&) = delete;
    Graph& operator=(const Graph&) = delete;
    
    // Разрешение перемещения
    Graph(Graph&&) = default;
    Graph& operator=(Graph&&) = default;
    
    // Основные методы
    void insertEdge(int x, int y, int weight = 0);
    void printGraph() const;
    void removeEdge(int x, int y);
    bool edgeExists(int x, int y) const;
    
    // Геттеры
    int getNumVertices() const { return nvertices; }
    int getNumEdges() const { return nedges; }
    bool isDirected() const { return directed; }
    const std::vector<int>& getDegrees() const { return degree; }
    
    // Алгоритмы на графах
    void BFS(int start) const;
    void DFS(int start) const;

private:
    void DFSUtil(int v, std::vector<bool>& visited) const;
};

#endif // L0704_244_HPP
