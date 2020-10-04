#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Priority.h"
#include "SorDLList.h"

template <class T>
class PriorityQueue {
    SorDLList<T> list;
    unsigned int capacity;
    unsigned int length;
public:
    PriorityQueue() : list(), capacity(-1), length(0) {}
    PriorityQueue(unsigned int max) : list(), capacity(max), length(0) {}
    void push(T elem) {
        if (length < capacity) {
            list.Insert(elem);
            ++length;
        }
    }
    void pop() {
        if (length > 0) {
            list.pop_front();
            --length;
        }
    }
    T top() {
        return list.front();
    }
    unsigned int max_size() const {
        return capacity;
    }
    unsigned int size() const {
        return length;
    }
    bool empty() const {
        return length == 0;
    }
};

#endif