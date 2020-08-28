#include <vector>
#include <iostream>
#include <string>
#include <limits>

/**
 *  Prints a given vector.
 *  
 *  @param vec The vector to be printed.
 */
template<class T>
void printv(const std::vector<T> & vec) {

    // Loop through each element and print them.
    for (T elem : vec) {
        std::cout << elem << " ";
    }

    // Print a newline.
    std::cout << std::endl;
}

/**
 *  Given a vector and two indices, swap the contents at the indices.
 *  
 *  @param vec The vector in question.
 *  @param a The index of one element.
 *  @param b The index of another element.
 */
template<class T>
void swapvp(std::vector<T> & vec, size_t a, size_t b) {

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
 *  @param vec The vector in question.
 *  @param start The start index (inclusive) of the sorting interval.
 *  @param end The ending index (inclusive) of the sorting interval.
 *  @return An index of an element that is placed in its final and correct position.
 */
template <class T>
size_t partition(std::vector<T> & vec, size_t start, size_t end) {
    
    // Store pivot as a temp variable.
    T pivot = vec.at(start);

    // Initialize left and right pointers.
    size_t l = start, r = end;


    // Do this while the pointers have not crossed.
    while (l < r) {

        // Move right pointer until we find an element that is less than pivot.
        while (vec.at(r) > pivot and l < r) {
            --r;
        }

        // Swap it with the left pointer.
        swapvp(vec, l, r);
        

        // Likewise, move left pointer until we find an element that is greater than pivot.
        while (vec.at(l) <= pivot and l < r) {
            ++l;
        }

        // Then, swap it with the right pointer.
        swapvp(vec, l, r);
    }


    // The pointers should now be equal to each other, and hovering over the pivot.
    vec.at(l) = pivot;
    return l;
}


/**
 *  Implements the QuickSort algorithm that runs in O(nlogn) in best case and O(n2) in worse case.
 *  Sorts a given vector within a given interval.
 * 
 *  @param vec The vector to be sorted.
 *  @param start The starting index (inclusive) of the interval to be sorted.
 *  @param end The ending index (inclusive) of the interval to be sorted.
 */
template <class T>
void quicksort(std::vector<T> & vec, size_t start, size_t end) {


    // Do not partition invalid parameters start >= end.
    if (start < end) {


        size_t partition_index = partition(vec, start, end);


        // Protect from overflow by not sorting left of partition if will overflow.
        if (partition_index != std::numeric_limits<size_t>::min())
            quicksort(vec, start, partition_index - 1);
        

        // Protect from overflow by not sorting right of index if will overflow.
        if (partition_index != std::numeric_limits<size_t>::max())
            quicksort(vec, partition_index + 1, end);
    }
}


/**
 *  Sorts a given vector using the QuickSort algorithm.
 * 
 *  @param vec The vector to be sorted.
 */
template <class T>
void quicksort(std::vector<T> & vec) {
    quicksort(vec, 0, vec.size() - 1);
}


int main() {
    std::string str = "GARFIELDYOUARESOFATWHYAREYOUSOBIGANDFAT";
    std::vector<char> vec(str.begin(), str.end());
    printv(vec);
    quicksort(vec);
    printv(vec);
    return 0;
}