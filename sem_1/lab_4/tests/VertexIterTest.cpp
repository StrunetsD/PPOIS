#include <gtest/gtest.h>
#include "../src/VertexIter.h"

#include <vector>
#include <iterator>

template <typename T>
class MockGraph {
public:
    using vertex_iterator = typename std::vector<T>::iterator;

    void add_vertex(const T& value) {
        vertices.push_back(value);
    }

    vertex_iterator begin() {
        return vertices.begin();
    }

    vertex_iterator end() {
        return vertices.end();
    }

    void erase_vertex(vertex_iterator it) {
        if (it != vertices.end()) {
            vertices.erase(it);
        }
    }

private:
    std::vector<T> vertices;
};

class VertexIteratorTest : public ::testing::Test {
protected:
    // Примерный граф
    MockGraph<int> graph;

    // Инициализация графа
    void SetUp() override {
        // Заполнение графа данными
        graph.add_vertex(1);
        graph.add_vertex(2);
        graph.add_vertex(3);
        graph.add_vertex(4);
    }
};

// Тест на инкремент итератора
TEST_F(VertexIteratorTest, TestIncrement) {
    auto it = graph.begin();

    // Проверяем, что на первой позиции стоит 1
    EXPECT_EQ(*it, 1);

    ++it;
    // Проверяем, что после инкремента на второй позиции стоит 2
    EXPECT_EQ(*it, 2);

    ++it;
    // Проверяем, что на третьей позиции стоит 3
    EXPECT_EQ(*it, 3);

    ++it;
    // Проверяем, что на последней позиции стоит 4
    EXPECT_EQ(*it, 4);
}

// Тест на декремент итератора
TEST_F(VertexIteratorTest, TestDecrement) {
    auto it = graph.end();
    --it;
    // Проверяем, что на первой позиции стоит 4
    EXPECT_EQ(*it, 4);

    --it;
    // Проверяем, что на второй позиции стоит 3
    EXPECT_EQ(*it, 3);

    --it;
    // Проверяем, что на третьей позиции стоит 2
    EXPECT_EQ(*it, 2);

    --it;
    // Проверяем, что на последней позиции стоит 1
    EXPECT_EQ(*it, 1);
}


// Тест на работу с пустым графом
TEST_F(VertexIteratorTest, TestEmptyGraph) {
    MockGraph<int> empty_graph;

    auto it = empty_graph.begin();
    auto end = empty_graph.end();

    // Проверяем, что итератор на пустом графе не может пройти
    EXPECT_EQ(it, end);
}
