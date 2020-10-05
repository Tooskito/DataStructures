// @author      Jonathan Abbott
// @date        Oct 4th, 2020
// @desc        This file defines a queue built on the first-in-priority-out principle.


#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H


#include "Priority.h"
#include "SorDLList.h"


// Implements a queue that operates on the first-in-priority-out principle.
// Objects in the queue are type Priority<T>.
template <class T>
class PriorityQueue {


    SorDLList<Priority<T>> mList;
    unsigned int mCapacity;
    unsigned int mLength;


public:


    // Default constructor and another constructor.
    PriorityQueue() : mList(), mCapacity(-1), mLength(0) {}
    PriorityQueue(unsigned int max) : mList(), mCapacity(max), mLength(0) {}
    // There is no destructor because when this goes out of scope it also destroys the DLList automatically.


    // Pushes a Priority element into the queue.
    void push(Priority<T> elem) {
        if (mLength < mCapacity) {
            mList.Insert(elem);
            ++mLength;
        }
    }


    // Removes the highest-priority element off of the queue.
    void pop() {
        if (mLength > 0) {
            mList.pop_front();
            --mLength;
        }
    }


    // Gets the highest-priority element on the queue.
    Priority<T> top() {
        return mList.front();
    }


    // Returns the max size of the queue, a.k.a. the maximum number of elements.
    unsigned int max_size() const {
        return mCapacity;
    }


    // Returns the length of the queue.
    unsigned int size() const {
        return mLength;
    }


    // Returns true if the queue is empty a.k.a. has no elements.
    bool empty() const {
        return mLength == 0;
    }


};

#endif