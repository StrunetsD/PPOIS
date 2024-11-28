#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "VertexIter.h"
#include "IncidentEdgeIterator.h"
#include "EdgeIter.h"

using namespace std;

template <typename T>
class Graph {
public:
    using vertex_iterator = typename vector<pair<T, vector<T>>>::iterator;
    using neighbor_iterator = typename vector<T>::iterator;


    using edge_iterator = EdgeIterator<Graph<T>, T>;

    int degree_of_vertex(const T& vertex) const {

        auto vertex_it = find_if(adjacency_list_.begin(), adjacency_list_.end(),
                                  [&vertex](const auto& vertex_pair) { return vertex_pair.first == vertex; });

        if (vertex_it == adjacency_list_.end()) {
            throw runtime_error("Vertex not found");
        }


        return vertex_it->second.size();
    }

    int degree_of_edge(const T& u, const T& v) const {
        if (!check_vertex(u) || !check_vertex(v)) {
            throw runtime_error("One or both vertices do not exist");
        }

        int degree_u = 0;
        int degree_v = 0;


        for (const auto& vertex : adjacency_list_) {
            if (vertex.first == u) {
                degree_u = vertex.second.size();
            }
            if (vertex.first == v) {
                degree_v = vertex.second.size();
            }
        }


        return degree_u + degree_v;
    }
    edge_iterator edges_begin() {
        return edge_iterator(adjacency_list_.begin(), adjacency_list_.end(),
                              adjacency_list_.begin()->second.begin());
    }

    edge_iterator edges_end() {
        return edge_iterator(adjacency_list_.end(), adjacency_list_.end(),
                              adjacency_list_.end()->second.end());
    }

    void add_vertex(const T& data) {
        if (check_vertex(data)) {
            throw runtime_error("Vertex already exists");
        }
        adjacency_list_.emplace_back(data, vector<T>());
    }

    vertex_iterator erase_vertex(vertex_iterator it) {
        for (auto& vertex : adjacency_list_) {
            auto& neighbors = vertex.second;
            neighbors.erase(remove(neighbors.begin(), neighbors.end(), it->first), neighbors.end());
        }
        return adjacency_list_.erase(it);
    }

    void delete_vertex(const T& data) {
        if (!check_vertex(data)) {
            throw runtime_error("Vertex does not exist");
        }

        for (auto& vertex : adjacency_list_) {
            auto& neighbors = vertex.second;
            neighbors.erase(remove(neighbors.begin(), neighbors.end(), data), neighbors.end());
        }
        adjacency_list_.erase(
            remove_if(adjacency_list_.begin(), adjacency_list_.end(),
                       [&data](const auto& vertex) { return vertex.first == data; }),
            adjacency_list_.end());
    }

    void add_edge(const T& u, const T& v) {
        if (!check_vertex(u) || !check_vertex(v)) {
            throw std::runtime_error("One or both vertices do not exist");
        }

        for (auto& vertex : adjacency_list_) {
            if (vertex.first == u && !check_edge(vertex.second, v)) {
                vertex.second.push_back(v);
            }
            if (vertex.first == v && !check_edge(vertex.second, u)) {
                vertex.second.push_back(u);
            }
        }
    }

    void delete_edge(const T& u, const T& v) {
        if (!check_vertex(u) || !check_vertex(v)) {
            throw runtime_error("One or both vertices do not exist");
        }

        for (auto& vertex : adjacency_list_) {
            if (vertex.first == u) {
                auto& neighbors = vertex.second;
                neighbors.erase(remove(neighbors.begin(), neighbors.end(), v), neighbors.end());
            }
            if (vertex.first == v) {
                auto& neighbors = vertex.second;
                neighbors.erase(remove(neighbors.begin(), neighbors.end(), u), neighbors.end());
            }
        }
    }

    void print() const {
        for (const auto& vertex : adjacency_list_) {
            cout << vertex.first << ": ";
            for (const auto& neighbor : vertex.second) {
                cout << neighbor << " ";
            }
            cout << "\n";
        }
    }

    int vertex_count() const {
        return adjacency_list_.size();
    }

    int edge_count() const {
        int count = 0;
        for (const auto& vertex : adjacency_list_) {
            count += vertex.second.size();
        }
        return count / 2;
    }

    bool check_vertex(const T& data) const {
        for (const auto& vertex : adjacency_list_) {
            if (vertex.first == data) {
                return true;
            }
        }
        return false;
    }

    bool check_edge(const vector<T>& neighbors, const T& target) const {
        for (const auto& neighbor : neighbors) {
            if (neighbor == target) {
                return true;
            }
        }
        return false;
    }


    vertex_iterator begin() {
        return adjacency_list_.begin();
    }

    vertex_iterator end() {
        return adjacency_list_.end();
    }

    IncidentEdgeIterator<Graph<T>, T> incident_edges(const T& vertex) {
        auto vertex_it = find_if(adjacency_list_.begin(), adjacency_list_.end(),
                                  [&vertex](const auto& vertex_pair) { return vertex_pair.first == vertex; });

        if (vertex_it == adjacency_list_.end()) {
            throw runtime_error("Vertex not found");
        }

        return IncidentEdgeIterator<Graph<T>, T>(vertex_it->second.begin(), vertex_it->second.end(), vertex);
    }

private:
    vector<pair<T, vector<T>>> adjacency_list_;
};
