#ifndef PRIORITY_H
#define PRIORITY_H

#include <iostream>

typedef unsigned int uint;

template <class T>
class Priority {
    T value;
    uint priority;
public:
    Priority() : value(), priority(0) {}
    Priority(T inValue, uint inPriority) : value(inValue), priority(inPriority) {}
    ~Priority() {}
    Priority& operator=(const Priority& assign) { 
        if (this != &assign) {
            this->value = assign.value;
            this->priority = assign.priority;
        }
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const Priority& other) {
        os << "{" << other.value << ", " << other.priority << "}";
        return os;
    }
    bool operator>(const Priority& other) const { return this->priority > other.priority; }
    bool operator>=(const Priority& other) const { return this->priority >= other.priority; }
    bool operator<(const Priority& other) const { return this->priority < other.priority; }
    bool operator<=(const Priority& other) const { return this->priority <= other.priority; }
    bool operator==(const Priority& other) const { return this->priority == other.priority; }
};

#endif