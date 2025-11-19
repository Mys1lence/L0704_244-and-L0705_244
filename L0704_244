#include "L0704_244.hpp"
#include <stdexcept>
#include <iostream>
#include <queue>
#include <stack>

Graph::Graph(int n, bool dir) 
    : nvertices(n), nedges(0), directed(dir), 
      edges(n), degree(n, 0) {
    
    if (n <= 0) {
        throw std::invalid_argument("Количество вершин должно быть положительным");
    }
}

void Graph::insertEdge(int x, int y, int weight) {
    // Проверка валидности вершин
    if (x < 0  x >= nvertices  y < 0 || y >= nvertices) {
        throw std::out_of_range("Неверные номера вершин: " + 
                               std::to_string(x) + " - " + std::to_string(y));
    }
    
    if (x == y) {
        throw std::invalid_argument("Петли не поддерживаются");
    }
    
    // Создание нового ребра
    auto newEdge = std::make_unique<EdgeNode>(y, weight);
    newEdge->next = std::move(edges[x]);
    edges[x] = std::move(newEdge);
    degree[x]++;
    nedges++;
    
    // Для неориентированного графа добавляем обратное ребро
    if (!directed && x != y) {
        auto reverseEdge = std::make_unique<EdgeNode>(x, weight);
        reverseEdge->next = std::move(edges[y]);
        edges[y] = std::move(reverseEdge);
        degree[y]++;
        // nedges не увеличиваем, т.к. уже увеличили выше
    }
}

void Graph::removeEdge(int x, int y) {
    if (x < 0  x >= nvertices  y < 0 || y >= nvertices) {
        throw std::out_of_range("Неверные номера вершин");
    }
    
    // Удаление ребра x->y
    EdgeNode current = reinterpret_cast<EdgeNode>(&edges[x]);
    while (*current != nullptr) {
        if ((*current)->y == y) {
            std::unique_ptr<EdgeNode> temp = std::move((*current)->next);
            *current = temp.release();
            degree[x]--;
            nedges--;
            break;
        }
        current = reinterpret_cast<EdgeNode**>(&(*current)->next);
    }
    
    // Для неориентированного графа удаляем обратное ребро
    if (!directed) {
        current = reinterpret_cast<EdgeNode**>(&edges[y]);
        while (*current != nullptr) {
            if ((*current)->y == x) {
                std::unique_ptr<EdgeNode> temp = std::move((*current)->next);
                *current = temp.release();
                degree[y]--;
                // nedges не уменьшаем, т.к. уже уменьшили выше
                break;
            }
            current = reinterpret_cast<EdgeNode**>(&(*current)->next);
        }
    }
}

bool Graph::edgeExists(int x, int y) const {
    if (x < 0  x >= nvertices  y < 0 || y >= nvertices) {
        return false;
    }
    
    EdgeNode* current = edges[x].get();
    while (current != nullptr) {
        if (current->y == y) {
            return true;
        }
        current = current->next.get();
    }
    return false;
}

void Graph::printGraph() const {
    std::cout << "Граф (" << (directed ? "ориентированный" : "неориентированный") 
              << "): " << nvertices << " вершин, " << nedges << " ребер\n";
    
    for (int i = 0; i < nvertices; ++i) {
        std::cout << "Вершина " << i << " (степень " << degree[i] << "): ";
        
        EdgeNode* current = edges[i].get();
        while (current != nullptr) {
            std::cout << i << "->" << current->y;
            if (current->weight != 0) {
                std::cout << "(" << current->weight << ")";
            }
            if (current->next != nullptr) {
                std::cout << ", ";
            }
            current = current->next.get();
        }
        std::cout << std::endl;
    }
}

void Graph::BFS(int start) const {
    if (start < 0 || start >= nvertices) {
        throw std::out_of_range("Неверная стартовая вершина");
    }
    
    std::vector<bool> visited(nvertices, false);
    std::queue<int> q;
    
    std::cout << "BFS начиная с вершины " << start << ": ";
