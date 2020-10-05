// @author      Jonathan Abbott
// @date        Oct 4th, 2020
// @desc        This file implements a DLList<T> that is sorted at all times.


#ifndef SORDLLIST_H
#define SORDLLIST_H


#include <iostream> // std::cout, std::endl
#include "DLList.h" // DLList<T>


// This class inherits a DLList<T> and adds an always-sorted property to it.
template <class T>
class SorDLList : public DLList<T> {


public:


    // Default constructor
    SorDLList() : DLList<T>() {}
    

    // Inserts an element into the list such that the element is in its sorted position.
    virtual void Insert (T value)
    {


        // Long type is necessary to reference parent's nested class.
        typename DLList<T>::node* temp = new typename DLList<T>::node(value);


        // If the list is empty, set the empty list to the added element.
        if ( this->IsEmpty() ) {


            this->head = temp;
            this->tail = temp;


        } else {


            typename DLList<T>::node* prev =  NULL;
            typename DLList<T>::node* curr = this->head;


            while (curr != NULL and temp->data > curr->data) {
                prev = curr;
                curr = curr->next;
            }


            // Curr is either at the head of the list, NULL at the element after the end of the list,
            // or set to the value that should come AFTER curr in the final, sorted list.
            if (prev == NULL) {


                // Add at head of list.
                temp->next = this->head;
                this->head->prev = temp;
                this->head = temp;


            } else if (curr == NULL) {


                // Add at end of list.
                temp->prev = this->tail;
                this->tail->next = temp;
                this->tail = temp;


            } else {


                // Insert element so element comes before curr and after prev in the final, sorted list.
                // I.e. prev <-> temp <-> curr
                temp->next = curr;
                curr->prev = temp;
                prev->next = temp;
                temp->prev = prev;


            }
        }
    }


    // Overload std::ostream insertion operator so that we can print this sorted doubly linked list.
    friend std::ostream& operator<<(std::ostream& os, const SorDLList<T>& list) {


        // Long type to reference parent's nested class.
        typename DLList<T>::node* curr;
        

        if (list.IsEmpty()) {
            os << "List is empty.";
        } else {
            curr = list.head;
            while (curr != NULL) {
                // Print every element until curr is null.
                os << curr->data << " ";
                curr = curr->next;
            }
        }

        
        return os;
    }
};

#endif