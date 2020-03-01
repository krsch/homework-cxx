#include "pqueue.hpp"
#include <string>

pqueue::handle pqueue::insert(int priority, std::string const& name) {
    auto iter = heap_positions.insert(heap_positions.begin(), heap.size());
    heap.emplace_back(heap_element{priority, iter, name});
    return iter;
}

void pqueue::erase(handle it) {
    size_t pos = *it;
    if (pos != heap.size() - 1) {
        std::swap(heap[pos], heap.back());
        *(heap[pos].iter) = pos;
    }
    heap.pop_back();
    heap_positions.erase(it);
}

void pqueue::update_priority(handle it, int new_priority) {
    heap[*it].priority = new_priority;
}

std::string pqueue::extract_min() {
    std::string s = heap.front().payload;
    heap_positions.erase(heap.front().iter);
    std::swap(heap.front(), heap.back());
    heap.pop_back();
    *(heap.front().iter) = 0;
    return s;
}

std::string const& pqueue::get(handle it) const {
    return heap[*it].payload;
}

int pqueue::get_priority(handle it) const {
    return heap[*it].priority;
}

size_t pqueue::size() const {
    return heap.size();
}