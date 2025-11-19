#include "L0704_244.hpp"
#include <iostream>
#include <cassert>

void testBasicOperations() {
    std::cout << "=== Тест основных операций ===" << std::endl;
    
    // Тест 1: Создание ориентированного графа
    Graph directedGraph(5, true);
    directedGraph.insertEdge(0, 1);
    directedGraph.insertEdge(1, 2);
    directedGraph.insertEdge(2, 3);
    directedGraph.insertEdge(3, 4);
    directedGraph.insertEdge(4, 0);
    
    std::cout << "Ориентированный граф:" << std::endl;
    directedGraph.printGraph();
    assert(directedGraph.getNumEdges() == 5);
    assert(directedGraph.edgeExists(0, 1));
    assert(!directedGraph.edgeExists(1, 0)); // Обратное ребро не должно существовать
    
    // Тест 2: Создание неориентированного графа
    Graph undirectedGraph(4, false);
    undirectedGraph.insertEdge(0, 1);
    undirectedGraph.insertEdge(1, 2);
    undirectedGraph.insertEdge(2, 3);
    undirectedGraph.insertEdge(3, 0);
    
    std::cout << "\nНеориентированный граф:" << std::endl;
    undirectedGraph.printGraph();
    assert(undirectedGraph.getNumEdges() == 4);
    assert(undirectedGraph.edgeExists(0, 1));
    assert(undirectedGraph.edgeExists(1, 0)); // Обратное ребро должно существовать
    
    // Тест 3: Граф с весами
    Graph weightedGraph(3, true);
    weightedGraph.insertEdge(0, 1, 5);
    weightedGraph.insertEdge(1, 2, 3);
    weightedGraph.insertEdge(2, 0, 7);
    
    std::cout << "\nВзвешенный ориентированный граф:" << std::endl;
    weightedGraph.printGraph();
}

void testAlgorithms() {
    std::cout << "\n=== Тест алгоритмов ===" << std::endl;
    
    Graph graph(6, false);
    graph.insertEdge(0, 1);
    graph.insertEdge(0, 2);
    graph.insertEdge(1, 3);
    graph.insertEdge(2, 4);
    graph.insertEdge(3, 5);
    
    std::cout << "Граф для алгоритмов:" << std::endl;
    graph.printGraph();
    
    graph.BFS(0);
    graph.DFS(0);
}

void testEdgeCases() {
    std::cout << "\n=== Тест граничных случаев ===" << std::endl;
    
    // Тест с одной вершиной
    Graph singleVertex(1, false);
    std::cout << "Граф с одной вершиной:" << std::endl;
    singleVertex.printGraph();
    
    // Тест удаления ребер
    Graph graph(3, false);
    graph.insertEdge(0, 1);
    graph.insertEdge(1, 2);
    
    std::cout << "\nДо удаления:" << std::endl;
    graph.printGraph();
    
    graph.removeEdge(0, 1);
    
    std::cout << "\nПосле удаления ребра 0-1:" << std::endl;
    graph.printGraph();
    assert(!graph.edgeExists(0, 1));
    assert(!graph.edgeExists(1, 0));
}

void testErrorHandling() {
    std::cout << "\n=== Тест обработки ошибок ===" << std::endl;
    
    Graph graph(3, false);
    
    try {
        graph.insertEdge(5, 1); // Неверная вершина
        assert(false); // Не должно дойти до этой точки
    } catch (const std::exception& e) {
        std::cout << "Поймано ожидаемое исключение: " << e.what() << std::endl;
    }
    
    try {
        graph.insertEdge(0, 0); // Петля
        assert(false);
    } catch (const std::exception& e) {
        std::cout << "Поймано ожидаемое исключение: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "Запуск тестов для L0704_244 - реализация графа на C++\n" << std::endl;
    
    testBasicOperations();
    testAlgorithms();
    testEdgeCases();
    testErrorHandling();
    
    std::cout << "\n=== Все тесты пройдены успешно! ===" << std::endl;
    
    return 0;
}
