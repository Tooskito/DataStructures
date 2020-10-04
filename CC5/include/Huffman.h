#ifndef PRIORITYTREE_H
#define PRIORITYTREE_H

#include <iostream>
#include <string>
#include <unordered_map>
#include "Priority.h"

template <class T>
class PriorityNode {
    Priority<T> data;
    PriorityNode* left;
    PriorityNode* right;
public:
    PriorityNode() : data(), left(nullptr), right(nullptr) {}
    PriorityNode(Priority<T> inData, PriorityNode* inLeft, PriorityNode* inRight)
        : data(inData), left(inLeft), right(inRight) {}
    // Copy constructor.
    PriorityNode(const PriorityNode& other)
        : data(other.data), left(other.left), right(other.right) {}
    // Destructor.
    ~PriorityNode() { 
        if (this->left != nullptr) delete this->left;
        if (this->right != nullptr) delete this->right;
    }
    // Copy assignment operator.
    PriorityNode& operator=(const PriorityNode& assign) {
        if (this != &assign) {
            this->data = assign.data;
            this->left = assign.left;
            this->right = assign.right;
        }
        return *this;
    }
    // Comparison operators.
    bool operator>(const PriorityNode& other) const { return this->data > other.data; }
    bool operator>=(const PriorityNode& other) const { return this->data >= other.data; }
    bool operator<(const PriorityNode& other) const { return this->data < other.data; }
    bool operator<=(const PriorityNode& other) const { return this->data <= other.data; }
    bool operator==(const PriorityNode& other) const { return this->data == other.data; }
    // Overload ostream.
    friend std::ostream& operator<<(std::ostream& os, const PriorityNode& node) {
        os << "{" << node.data << "} ";
        return os;
    }
};

#endif