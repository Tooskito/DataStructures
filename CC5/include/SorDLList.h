#ifndef SORDLLIST_H
#define SORDLLIST_H

#include <iostream>
#include "DLList.h"

template <class T>
class SorDLList : public DLList<T> {

public:
    SorDLList() : DLList<T>() {}
    virtual void Insert (T value)
    {
        typename DLList<T>::node* temp = new typename DLList<T>::node(value);
        if (IsEmpty()){
            head = temp;
            tail = temp;
        } else {
            typename DLList<T>::node* prev =  NULL;
            typename DLList<T>::node* curr = head;

            /* traverse the list until the end */
            while (curr != NULL)
            {
                prev = curr;
                curr = curr->next;
            }
        
            /* insert the node, temp, at the end */
            prev -> next = temp;
            
            /* Allocate the previous node */
            prev -> next -> prev = prev;
            
            /* Allocate tail */
            tail = prev -> next;
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const SorDLList<T>& list) {
        typename DLList<T>::node* curr;
        if (list.IsEmpty()) {
            os << "List is empty.";
        } else {
            curr = list.head;
            while (curr != NULL) {
                os << curr->data << " ";
                curr = curr->next;
            }
        }
        return os;
    }
};

#endif