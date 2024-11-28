#include <gtest/gtest.h>
#include "../src/Graph.h"
class GraphTest : public ::testing::Test {
protected:
    Graph<int> graph;

    void SetUp() override {
        // Добавляем тестовые вершины и рёбра
        graph.add_vertex(1);
        graph.add_vertex(2);
        graph.add_vertex(3);
        graph.add_edge(1, 2);
        graph.add_edge(1, 3);
        graph.add_edge(2, 3);
    }
};

TEST_F(GraphTest, TestAddVertex) {
    EXPECT_EQ(graph.vertex_count(), 3);  // Проверяем, что 3 вершины
    graph.add_vertex(4);
    EXPECT_EQ(graph.vertex_count(), 4);  // Проверяем, что теперь 4 вершины
}



TEST_F(GraphTest, TestDeleteEdge) {
    graph.delete_edge(1, 2);
    EXPECT_EQ(graph.edge_count(), 2);  // Проверяем, что теперь 2 рёбра
    graph.delete_edge(1, 3);
    EXPECT_EQ(graph.edge_count(), 1);  // Проверяем, что теперь 1 ребро
}

TEST_F(GraphTest, TestDeleteVertex) {
    graph.delete_vertex(2);
    EXPECT_EQ(graph.vertex_count(), 2);  // Проверяем, что осталось 2 вершины
    EXPECT_EQ(graph.edge_count(), 1);    // Проверяем, что осталось 1 ребро (1 <-> 3)
}



TEST_F(GraphTest, TestPrint) {
    // Здесь можно сделать тест, проверяющий вывод, если это необходимо
    // Для простоты можно использовать Google Mock или перенаправление вывода
}
