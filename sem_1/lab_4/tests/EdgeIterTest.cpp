#include <gtest/gtest.h>
#include "../src/EdgeIter.h"
#include <vector>

template <typename T>
struct Graph {
    using vertex_iterator = typename std::vector<std::pair<T, std::vector<T>>>::iterator;
    using neighbor_iterator = typename std::vector<T>::iterator;

    std::vector<std::pair<T, std::vector<T>>> adjacency_list;

    vertex_iterator begin() {
        return adjacency_list.begin();
    }

    vertex_iterator end() {
        return adjacency_list.end();
    }
};


class EdgeIteratorTest : public ::testing::Test {
protected:
    using GraphType = Graph<int>;

    void SetUp() override {
        // Create a graph for testing
        graph.adjacency_list = {
            {1, {2, 3}},
            {2, {1, 4}},
            {3, {1}},
            {4, {2}}
        };
    }

    GraphType graph;
};



TEST_F(EdgeIteratorTest, EdgeDeletion) {
    // Create an EdgeIterator starting at the first vertex
    EdgeIterator<Graph<int>, int> it(graph.begin(), graph.begin()->second.begin());

    // Delete the first edge (1 -> 2)
    it.delete_edge();

    // Check that the edge was removed
    ASSERT_EQ(graph.adjacency_list[0].second, std::vector<int>({3}));
}


TEST_F(EdgeIteratorTest, EqualityAndInequality) {
    // Create two iterators
    EdgeIterator<Graph<int>, int> it1(graph.begin(), graph.begin()->second.begin());
    EdgeIterator<Graph<int>, int> it2(graph.begin(), graph.begin()->second.begin());

    // Test equality
    ASSERT_TRUE(it1 == it2);

    // Increment one iterator
    ++it1;

    // Test inequality
    ASSERT_TRUE(it1 != it2);

    // Increment the second iterator
    ++it2;

    // Test equality again
    ASSERT_TRUE(it1 == it2);
}






