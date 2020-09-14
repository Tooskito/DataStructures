/**
 *  @author Jonathan Abbott
 *  @date   Sep 13, 2020
 *  
 *  Includes declaration and definition of a double-hashing hash-table.
 */

// Standard include guards.
#ifndef DOUBLEHASH_H
#define DOUBLEHASH_H


#include <iostream>         // std::ostream
#include <string>           // std::string
#include "LinearProbe.h"    // HashTable<Key, Value>


/**
 *  Inherits from LinearProbe HashTable but modifies it such that each entry
 *  goes through two hashing functions to determine where it is placed in the
 *  HashTable.
 */
template <class Key, class Value>
class DoubleHash : public HashTable<Key, Value> {
protected:


    // Second hash function that takes an integer.
    long unsigned int HashFunc2(const int& keyToTranslate) const
    {
        if (keyToTranslate < 0){
            return (long unsigned int)(-1 * keyToTranslate);
        }

        return (long unsigned int)(3 - keyToTranslate % 3);
    }

    
    // Second hash function that takes a string.
    long unsigned int HashFunc2(const std::string& keyToTranslate) const
    {
        return (long unsigned int)(3 - keyToTranslate.size() % 3);
    }


public:
    // Standard constructor and destructor.
    DoubleHash(const unsigned int size = 0) : HashTable<Key, Value>(size) {}
    virtual ~DoubleHash() {}


    // Overwrite parent's definition of `findPos`.
    long unsigned int findPos( const Key& theKey ) const
    {
        
        long unsigned int currentPos;
        long unsigned int iter = 1;

        // But instead we change the stepsize to the second hashing function.
        const long unsigned int STEPSIZE = HashFunc2( theKey );
        
        do{
            // Hash Function determines current position
            currentPos = (this->HashFunc( theKey ) + iter*STEPSIZE) % this->array.capacity();
            ++iter;
        }
        while(
            this->array.at( currentPos ).state != EMPTY
            && this->array.at( currentPos ).state != DELETED
            && this->array.at( currentPos ).key != theKey
            && iter - 1 < this->array.capacity()
        );
        
        // Return capacity if the current value isn't the key. For safety
        if(this->array.at( currentPos ).state == ACTIVE 
            && this->array.at( currentPos ).key != theKey ){
                return this->array.capacity();
            }
        
        return currentPos;
    }

    // Overloaded Friend Operator
    friend std::ostream& operator<<( std::ostream& output, const DoubleHash<Key, Value>& theTable ){
        output << "Double Hash Results:" << std::endl;
        output << "# of Hashed Elements: " << theTable.numHash << " ";
        output << "Hash Capacity: " << theTable.array.size() << std::endl;
        
        for(unsigned int iter = 0; iter < theTable.array.size(); iter++){
            
            output << "{" << iter << ": ";
            
            if( theTable.array[iter].state == ACTIVE ){
            
                output << "ACTIVE, ";
            
            }
            else if( theTable.array[iter].state == DELETED ){
            
                output << "DELETED, ";
            
            }
            else{
                
                output << "EMPTY, ";
            }
            
            output << theTable.array[iter].key << ", ";
            
            output << theTable.array[iter].value << "}" << std::endl;
            
        }
        return output;
    }
};

#endif