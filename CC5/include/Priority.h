#ifndef PRIORITY_H
#define PRIORITY_H

#include <iostream>

template <class T>
class Priority {
    T value;
    unsigned int priority;
public:
    // Constructors.
    Priority() : value(), priority(0) {}
    Priority(T inValue, uint inPriority) : value(inValue), priority(inPriority) {}
    // Destructor.
    ~Priority() {}
    // Copy assignment operator.
    Priority& operator=(const Priority& assign) { 
        if (this != &assign) {
            this->value = assign.value;
            this->priority = assign.priority;
        }
        return *this;
    }
    // Overload ostream operator.
    friend std::ostream& operator<<(std::ostream& os, const Priority& other) {
        os << "{" << other.value << ", " << other.priority << "}";
        return os;
    }
    // Comparison operators.
    bool operator>(const Priority& other) const { return this->priority > other.priority; }
    bool operator>=(const Priority& other) const { return this->priority >= other.priority; }
    bool operator<(const Priority& other) const { return this->priority < other.priority; }
    bool operator<=(const Priority& other) const { return this->priority <= other.priority; }
    bool operator==(const Priority& other) const { return this->priority == other.priority; }
};

#endif