#include <gtest/gtest.h>
#include "../src/IncidentEdgeIterator.h"
#include <unordered_map>
#include <vector>

class MockGraph {
public:
    using T = int;
    using neighbor_iterator = std::vector<T>::iterator;

    std::unordered_map<T, std::vector<T>> vertices;

    MockGraph() {
        // Создаем пример графа
        vertices[1] = {2, 3};
        vertices[2] = {1};
        vertices[3] = {1};
    }

    // Для удобства, возвращаем итераторы для рёбер
    neighbor_iterator neighbors_begin(T vertex) {
        return vertices[vertex].begin();
    }

    neighbor_iterator neighbors_end(T vertex) {
        return vertices[vertex].end();
    }
};

// Тест: Инициализация и разыменовывание
TEST(IncidentEdgeIteratorTest, InitializationTest) {
    MockGraph graph;
    auto edge_it = graph.neighbors_begin(1);
    auto edge_end = graph.neighbors_end(1);
    IncidentEdgeIterator<MockGraph, int> it(edge_it, edge_end, 1);

    ASSERT_EQ(*it, std::make_pair(1, 2));  // Первое ребро должно быть (1, 2)
    ++it;
    ASSERT_EQ(*it, std::make_pair(1, 3));  // Следующее ребро должно быть (1, 3)
}

// Тест: Операция инкремента
TEST(IncidentEdgeIteratorTest, IncrementOperatorTest) {
    MockGraph graph;
    auto edge_it = graph.neighbors_begin(1);
    auto edge_end = graph.neighbors_end(1);
    IncidentEdgeIterator<MockGraph, int> it(edge_it, edge_end, 1);

    ++it;
    ASSERT_EQ(*it, std::make_pair(1, 3));  // Второе ребро должно быть (1, 3)
    ++it;
}

// Тест: Операция декремента
TEST(IncidentEdgeIteratorTest, DecrementOperatorTest) {
    MockGraph graph;
    auto edge_it = graph.neighbors_begin(1);
    auto edge_end = graph.neighbors_end(1);
    IncidentEdgeIterator<MockGraph, int> it(edge_end, edge_end, 1);

    --it;
    ASSERT_EQ(*it, std::make_pair(1, 3));  // Второе ребро должно быть (1, 3)
    --it;
    ASSERT_EQ(*it, std::make_pair(1, 2));  // Первое ребро должно быть (1, 2)
}

// Тест: Сравнение итераторов
TEST(IncidentEdgeIteratorTest, ComparisonOperatorTest) {
    MockGraph graph;
    auto edge_it = graph.neighbors_begin(1);
    auto edge_end = graph.neighbors_end(1);
    IncidentEdgeIterator<MockGraph, int> it1(edge_it, edge_end, 1);
    IncidentEdgeIterator<MockGraph, int> it2(edge_it, edge_end, 1);

    ASSERT_TRUE(it1 == it2);  // Итераторы должны быть равны на старте
    ++it1;
    ASSERT_TRUE(it1 != it2);  // После инкремента итераторы должны быть разные
}

// Тест: Проверка функции is_incident_to
TEST(IncidentEdgeIteratorTest, IsIncidentToTest) {
    MockGraph graph;
    auto edge_it = graph.neighbors_begin(1);
    auto edge_end = graph.neighbors_end(1);
    IncidentEdgeIterator<MockGraph, int> it(edge_it, edge_end, 1);

    ASSERT_TRUE(it.is_incident_to(2));  // Ребро (1, 2) инцидентно вершине 1
    ++it;
    ASSERT_TRUE(it.is_incident_to(3));  // Ребро (1, 3) инцидентно вершине 1
}

// Тест: Ошибка при разыменовывании недействительного итератора
TEST(IncidentEdgeIteratorTest, DereferenceInvalidIteratorTest) {
    MockGraph graph;
    auto edge_it = graph.neighbors_begin(1);
    auto edge_end = graph.neighbors_end(1);
    IncidentEdgeIterator<MockGraph, int> it(edge_end, edge_end, 1);

    ASSERT_THROW(*it, std::runtime_error);  // Попытка разыменовать недействительный итератор
}

// Тест: Ошибка при инкременте недействительного итератора
TEST(IncidentEdgeIteratorTest, IncrementInvalidIteratorTest) {
    MockGraph graph;
    auto edge_it = graph.neighbors_begin(1);
    auto edge_end = graph.neighbors_end(1);
    IncidentEdgeIterator<MockGraph, int> it(edge_end, edge_end, 1);

    ASSERT_THROW(++it, std::runtime_error);  // Попытка инкрементировать недействительный итератор
}



