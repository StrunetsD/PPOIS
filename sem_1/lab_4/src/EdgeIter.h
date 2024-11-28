#pragma once
#include <iostream>
#include <vector>
using namespace std;

#ifndef EDGEITER_H
#define EDGEITER_H

template <typename GraphType, typename T>
class EdgeIterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = std::pair<T, T>;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;


    explicit EdgeIterator(typename GraphType::vertex_iterator vertex_it,
                          typename GraphType::neighbor_iterator edge_it = typename GraphType::neighbor_iterator())
        : vertex_it_(vertex_it), edge_it_(edge_it) {}

    pointer operator->() {
        return &(*edge_it_);
    }


    EdgeIterator& operator++() {
        ++edge_it_;
        if (edge_it_ == vertex_it_->second.end()) {
            ++vertex_it_;

            if (vertex_it_ != adjacency_list_.end()) {
                edge_it_ = vertex_it_->second.begin();
            }
        }
        return *this;
    }


    EdgeIterator operator++(int) {
        EdgeIterator tmp = *this;
        ++(*this);
        return tmp;
    }


    EdgeIterator& operator--() {
        if (edge_it_ == vertex_it_->second.begin()) {
            --vertex_it_;
            edge_it_ = vertex_it_->second.end();
        }
        --edge_it_;
        return *this;
    }


    EdgeIterator operator--(int) {
        EdgeIterator tmp = *this;
        --(*this);
        return tmp;
    }

    bool operator==(const EdgeIterator& other) const {
        return vertex_it_ == other.vertex_it_ && edge_it_ == other.edge_it_;
    }

    bool operator!=(const EdgeIterator& other) const {
        return !(*this == other);
    }


    void delete_edge() {
        if (vertex_it_ != adjacency_list_.end() && edge_it_ != vertex_it_->second.end()) {
            edge_it_ = vertex_it_->second.erase(edge_it_);
        }
    }

private:
    typename GraphType::vertex_iterator vertex_it_;
    typename GraphType::neighbor_iterator edge_it_;
    vector<pair<T, std::vector<T>>> adjacency_list_{};
};

#endif
