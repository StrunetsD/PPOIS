#ifndef INCIDENTEDGEITERATOR_H
#define INCIDENTEDGEITERATOR_H

#include <stdexcept>
#include <utility>

template <typename GraphType, typename T>
class IncidentEdgeIterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = std::pair<T, T>;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;

    explicit IncidentEdgeIterator(typename GraphType::neighbor_iterator edge_it,
                                   typename GraphType::neighbor_iterator edge_end,
                                   const T& vertex)
        : edge_it_(edge_it), edge_end_(edge_end), vertex_(vertex), is_valid_(edge_it != edge_end) {}

    reference operator*() {
        validate_dereference();
        current_edge_ = std::make_pair(vertex_, *edge_it_);
        return current_edge_;
    }

    pointer operator->() {
        validate_dereference();
        current_edge_ = std::make_pair(vertex_, *edge_it_);
        return &current_edge_;
    }

    IncidentEdgeIterator& operator++() {
        validate_increment();
        ++edge_it_;
        update_valid_state();
        return *this;
    }

    IncidentEdgeIterator operator++(int) {
        IncidentEdgeIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    IncidentEdgeIterator& operator--() {
        validate_decrement();
        --edge_it_;
        update_valid_state();
        return *this;
    }

    IncidentEdgeIterator operator--(int) {
        IncidentEdgeIterator tmp = *this;
        --(*this);
        return tmp;
    }

    bool operator==(const IncidentEdgeIterator& other) const {
        return edge_it_ == other.edge_it_;
    }

    bool operator!=(const IncidentEdgeIterator& other) const {
        return !(*this == other);
    }

    bool is_incident_to(const T& vertex) const {
        validate_dereference();
        return *edge_it_ == vertex;
    }

private:
    typename GraphType::neighbor_iterator edge_it_;
    typename GraphType::neighbor_iterator edge_end_;
    T vertex_;
    bool is_valid_;
    mutable value_type current_edge_;

    void validate_dereference() const {
        if (!is_valid_) {
            throw std::runtime_error("Cannot dereference an invalid IncidentEdgeIterator.");
        }
    }

    void validate_increment() const {
        if (!is_valid_) {
            throw std::runtime_error("Increment operation on invalid iterator.");
        }
    }

    void validate_decrement() const {
        if (edge_it_ == typename GraphType::neighbor_iterator()) {
            throw std::runtime_error("Decrement operation on invalid iterator.");
        }
    }

    void update_valid_state() {
        is_valid_ = (edge_it_ != edge_end_);
    }
};

#endif // INCIDENTEDGEITERATOR_H
