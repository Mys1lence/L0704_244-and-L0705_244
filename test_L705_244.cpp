#include "L0705_244.hpp"
#include <iostream>

int main() {
    std::cout << "=== ПРОСТЫЕ ТЕСТЫ ДЛЯ ГРАФА L0705_244 ===\n" << std::endl;
    
    // Тест 1: Создание неориентированного графа (как в оригинальном коде)
    std::cout << "1. Неориентированный граф:" << std::endl;
    graph g(5, false);  // 5 вершин, неориентированный
    
    // Добавляем ребра (индексы с 1)
    g.insert_edge(1, 2, false);
    g.insert_edge(1, 5, false);
    g.insert_edge(2, 3, false);
    g.insert_edge(2, 4, false);
    g.insert_edge(2, 5, false);
    g.insert_edge(3, 4, false);
    g.insert_edge(4, 5, false);
    
    g.print_graph();
    std::cout << std::endl;
    
    // Тест 2: Ориентированный граф
    std::cout << "2. Ориентированный граф:" << std::endl;
    graph directed_g(4, true);  // 4 вершины, ориентированный
    
    directed_g.insert_edge(1, 2, true);
    directed_g.insert_edge(2, 3, true);
    directed_g.insert_edge(3, 4, true);
    directed_g.insert_edge(4, 1, true);
    
    directed_g.print_graph();
    std::cout << std::endl;
    
    // Тест 3: Граф с весами
    std::cout << "3. Граф с весами:" << std::endl;
    graph weighted_g(3, false);
    
    weighted_g.insert_edge(1, 2, false, 5);
    weighted_g.insert_edge(2, 3, false, 3);
    weighted_g.insert_edge(3, 1, false, 7);
    
    weighted_g.print_graph();
    
    std::cout << "\n=== ТЕСТЫ ЗАВЕРШЕНЫ ===" << std::endl;
    
    return 0;
}
