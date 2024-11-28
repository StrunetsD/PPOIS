#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

#ifndef VERTEXITER_H
#define VERTEXITER_H

template <typename GraphType, typename T>
class VertexIterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;


    explicit VertexIterator(typename GraphType::vertex_iterator current, typename GraphType::vertex_iterator end)
        : current_vertex_(current), end_vertex_(end), is_valid_(current != end) {}


    reference operator*() {
        validate_dereference();
        return current_vertex_->first;
    }

    pointer operator->() {
        validate_dereference();
        return &(current_vertex_->first);
    }


    VertexIterator& operator++() {
        validate_increment();
        ++current_vertex_;
        is_valid_ = (current_vertex_ != end_vertex_);
        return *this;
    }

    VertexIterator operator++(int) {
        VertexIterator tmp = *this;
        ++(*this);
        return tmp;
    }


    VertexIterator& operator--() {
        validate_decrement();
        --current_vertex_;
        is_valid_ = true;
        return *this;
    }

    VertexIterator operator--(int) {
        VertexIterator tmp = *this;
        --(*this);
        return tmp;
    }


    void remove_vertex(GraphType& graph) {
        if (!is_valid_) {
            throw std::runtime_error("Cannot remove invalid vertex");
        }
        current_vertex_ = graph.erase_vertex(current_vertex_);
        is_valid_ = (current_vertex_ != end_vertex_);
    }


    bool operator==(const VertexIterator& other) const {
        return current_vertex_ == other.current_vertex_;
    }

    bool operator!=(const VertexIterator& other) const {
        return !(*this == other);
    }

private:
    typename GraphType::vertex_iterator current_vertex_;
    typename GraphType::vertex_iterator end_vertex_;
    bool is_valid_;

    void validate_dereference() const {
        if (!is_valid_) {
            throw std::runtime_error("Cannot dereference an invalid iterator");
        }
    }

    void validate_increment() const {
        if (!is_valid_ || current_vertex_ == end_vertex_) {
            throw std::runtime_error("Increment operation on invalid or end iterator");
        }
    }

    void validate_decrement() const {
        if (!is_valid_ || current_vertex_ == end_vertex_) {
            throw std::runtime_error("Decrement operation on invalid or begin iterator");
        }
    }
};

#endif // VERTEXITER_H
