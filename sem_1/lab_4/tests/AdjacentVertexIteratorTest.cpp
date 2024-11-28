#include <gtest/gtest.h>
#include "../src/AdjacentVertexIterator.h"
#include <vector>
#include <stdexcept>

class GraphMock {
public:
    using neighbor_iterator = std::vector<int>::iterator;
    std::vector<int> neighbors;

    GraphMock(std::initializer_list<int> neighbor_list) : neighbors(neighbor_list) {}

    neighbor_iterator begin() {
        return neighbors.begin();
    }

    neighbor_iterator end() {
        return neighbors.end();
    }
};


TEST(AdjacentVertexIteratorTest, DereferenceAndIncrement) {
    GraphMock graph({1, 2, 3, 4});
    AdjacentVertexIterator<GraphMock, int> it(graph.begin(), graph.end());


    EXPECT_EQ(*it, 1);


    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
}





TEST(AdjacentVertexIteratorTest, Equality) {
    GraphMock graph({1, 2, 3});
    AdjacentVertexIterator<GraphMock, int> it1(graph.begin(), graph.end());
    AdjacentVertexIterator<GraphMock, int> it2(graph.begin(), graph.end());


    EXPECT_TRUE(it1 == it2);
    ++it1;
    EXPECT_FALSE(it1 == it2);
}


TEST(AdjacentVertexIteratorTest, InvalidDereference) {
    GraphMock graph({1, 2, 3});
    AdjacentVertexIterator<GraphMock, int> it(graph.end(), graph.end());


    EXPECT_THROW(*it, std::runtime_error);
}


TEST(AdjacentVertexIteratorTest, IsAdjacentTo) {
    GraphMock graph({1, 2, 3, 4});
    AdjacentVertexIterator<GraphMock, int> it(graph.begin(), graph.end());


    EXPECT_TRUE(it.is_adjacent_to(2));
    EXPECT_FALSE(it.is_adjacent_to(5));
}

TEST(AdjacentVertexIteratorTest, EmptyGraph) {
    GraphMock graph({});
    AdjacentVertexIterator<GraphMock, int> it(graph.begin(), graph.end());


    EXPECT_THROW(*it, std::runtime_error);
    EXPECT_THROW(++it, std::runtime_error);
}


TEST(AdjacentVertexIteratorTest, EmptyGraphDecrementIncrement) {
    GraphMock graph({});
    AdjacentVertexIterator<GraphMock, int> it(graph.end(), graph.end());


    EXPECT_THROW(++it, std::runtime_error);
    EXPECT_THROW(--it, std::runtime_error);
}