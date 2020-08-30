#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::srand

#ifndef CC2_QUICK_H_
#define CC2_QUICK_H_

/**
 *  Prints a given vector.
 *  
 *  @param vec The vector to be printed.
 */
template<class T>
void PrintVector(const std::vector<T> & vec) {

    // Loop through each element and print them.
    for (T elem : vec) {
        std::cout << elem << " ";
    }

    // Print a newline.
    std::cout << std::endl;
}


/**
 *  Namespace that declares and defines all the methods used for QuickSort.
 */
namespace Quick {


    /**
     *  Given a vector and two indices, swap the contents at the indices.
     *  
     *  @param vec The vector in question.
     *  @param a The index of one element.
     *  @param b The index of another element.
     */
    template<class T>
    void Swap(std::vector<T> & vec, int64_t a, int64_t b) {

        // Do the swap.
        T temp = vec.at(a);
        vec.at(a) = vec.at(b);
        vec.at(b) = temp;
    }


    /**
     *  Returns an index of an element that is placed in its correct place in the final vector.
     *  All elements to its left are less than it, and all elements to its right are greater.
     *  A vital component of quicksort.
     *  
     *  From: https://www.youtube.com/watch?v=x2LEyLvW0Lw
     *  
     *  @param vec The vector in question.
     *  @param start The start index (inclusive) of the sorting interval.
     *  @param end The ending index (inclusive) of the sorting interval.
     *  @return An index of an element that is placed in its final and correct position.
     */
    template <class T>
    int64_t  Partition(std::vector<T> & vec, int64_t start, int64_t end) {

        // Initialize left and right pointers.
        int64_t left = start, right = end + 1;


        // Do this while the pointers have not crossed.
        while (true) {

            
            // Increment left pointer until we either reach the end or find an element
            // that is greater than or equal to the pivot.
            while (vec.at(++left) < vec.at(start))
                if (left == end) break;
            

            // Decrement right pointer until we either reach the start or find an element
            // that is less than the pivot.
            while (vec.at(start) < vec.at(--right))
                if (right == start) break;
            

            // Break if our pointers have crossed.
            if (left >= right) break;


            // Otherwise, swap left and right pointers, and continue to next iteration.
            Swap(vec, left, right);
        }


        // The pointers should now have crossed. Place pivot in final destination.
        Swap(vec, start, right);
        return right;
    }


    /**
     *  Implements the QuickSort algorithm that runs in O(nlogn) in best case and O(n2) in worse case.
     *  Sorts a given vector within a given interval.
     * 
     *  From: https://www.youtube.com/watch?v=x2LEyLvW0Lw
     * 
     *  @param vec The vector to be sorted.
     *  @param start The starting index (inclusive) of the interval to be sorted.
     *  @param end The ending index (inclusive) of the interval to be sorted.
     */
    template <class T>
    void Sort(std::vector<T> & vec, int64_t start, int64_t end) {
        
        // Do not partition invalid parameters start >= end.
        if (start >= end)
            return;

        // `partition_index` is index of value that is in final destination.
        int64_t partition_index = Partition(vec, start, end);

        // Sort left and right sub-arrays.
        Sort(vec, start, partition_index - 1);
        Sort(vec, partition_index + 1, end);
    }


    /**
     *  Sorts a given vector using the QuickSort algorithm.
     * 
     *  @param vec The vector to be sorted.
     */
    template <class T>
    void Sort(std::vector<T> & vec) {
        
        // Seed random generator and shuffle to average out worst case.
        std::srand(unsigned( std::time(0) ));
        std::random_shuffle(vec.begin(), vec.end());
        
        // Now, call QuickSort.
        Sort(vec, 0, vec.size() - 1);
    }
}

#endif