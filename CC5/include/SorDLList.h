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

        if ( this->IsEmpty() ) {
            //std::cout << "Empty! Adding " << temp->data << " to the queue." << std::endl;
            this->head = temp;
            this->tail = temp;
        } else {
            typename DLList<T>::node* prev =  NULL;
            typename DLList<T>::node* curr = this->head;

            while (curr != NULL and temp->data < curr->data) {
                // Move insertion point until priority is >= point.
                prev = curr;
                curr = curr->next;
            }

            if (prev == NULL) {
                // Add at head of list.
                //std::cout << "Placing " << temp->data << " at head of list." << std::endl;
                temp->next = this->head;
                this->head->prev = temp;
                this->head = temp;
            } else if (curr == NULL) {
                //std::cout << "Placing " << temp->data << " at tail of list." << std::endl;
                temp->prev = this->tail;
                this->tail->next = temp;
                this->tail = temp;
            } else {
                //std::cout << "Replacing " << curr->data << " with " << temp->data << std::endl;
                temp->next = curr;
                curr->prev = temp;
                prev->next = temp;
                temp->prev = prev;
            }
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