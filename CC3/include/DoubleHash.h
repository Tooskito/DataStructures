#include <iostream>
#include <string>

#include "LinearProbe.h"

template <class Key, class Value>
class DoubleHash : public HashTable<Key, Value> {
protected:

    long unsigned int HashFunc2(const int& keyToTranslate) const
    {
        if (keyToTranslate < 0){
            return (long unsigned int)(-1 * keyToTranslate);
        }

        return (long unsigned int)(3 - keyToTranslate % 3);
    }

    
    long unsigned int HashFunc2(const std::string& keyToTranslate) const
    {
        return (long unsigned int)(3 - keyToTranslate.size() % 3);
    }


public:
    DoubleHash(const unsigned int size = 0) : HashTable<Key, Value>(size) {}
    virtual ~DoubleHash() {}


    long unsigned int findPos( const Key& theKey ) const
    {
        
        long unsigned int currentPos;
        long unsigned int iter = 1;
        const unsigned int STEPSIZE = HashFunc2( theKey );
        
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