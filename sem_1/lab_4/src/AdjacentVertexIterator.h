#ifndef ADJACENTVERTEXITERATOR_H
#define ADJACENTVERTEXITERATOR_H

#include <stdexcept>
#include <algorithm>

template <typename GraphType, typename T>
class AdjacentVertexIterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;


    explicit AdjacentVertexIterator(typename GraphType::neighbor_iterator neighbor_it,
                                     typename GraphType::neighbor_iterator neighbor_end)
        : neighbor_it_(neighbor_it), neighbor_end_(neighbor_end), is_valid_(neighbor_it != neighbor_end) {}


    reference operator*() {
        validate_dereference();
        return *neighbor_it_;
    }

    pointer operator->() {
        validate_dereference();
        return &(*neighbor_it_);
    }


    AdjacentVertexIterator& operator++() {
        validate_increment();
        ++neighbor_it_;
        update_valid_state();
        return *this;
    }

    AdjacentVertexIterator operator++(int) {
        AdjacentVertexIterator tmp = *this;
        ++(*this);
        return tmp;
    }


    AdjacentVertexIterator& operator--() {
        validate_decrement();
        --neighbor_it_;
        update_valid_state();
        return *this;
    }

    AdjacentVertexIterator operator--(int) {
        AdjacentVertexIterator tmp = *this;
        --(*this);
        return tmp;
    }


    bool operator==(const AdjacentVertexIterator& other) const {
        return neighbor_it_ == other.neighbor_it_;
    }

    bool operator!=(const AdjacentVertexIterator& other) const {
        return !(*this == other);
    }


    bool is_adjacent_to(const T& vertex) const {
        return std::find(neighbor_it_, neighbor_end_, vertex) != neighbor_end_;
    }

private:
    typename GraphType::neighbor_iterator neighbor_it_;
    typename GraphType::neighbor_iterator neighbor_end_;
    bool is_valid_;


    void validate_dereference() const {
        if (!is_valid_) {
            throw std::runtime_error("Cannot dereference an invalid AdjacentVertexIterator.");
        }
    }

    void validate_increment() const {
        if (!is_valid_) {
            throw std::runtime_error("Increment operation on invalid iterator.");
        }
    }

    void validate_decrement() const {
        if (!is_valid_) {
            throw std::runtime_error("Decrement operation on invalid iterator.");
        }
    }

    void update_valid_state() {
        is_valid_ = (neighbor_it_ != neighbor_end_);
    }
};

#endif // ADJACENTVERTEXITERATOR_H
