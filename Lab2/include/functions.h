/**
 *  @author Jonathan Abbott
 *  @date   Aug 24, 2020
 * 
 *  This file defines and implements functions for "Lab2" for CSE 20312,
 *  including that which finds the longest increasing subsequence of a
 *  given vector.
 */


#include <iostream>
#include <vector>


/**
 *  Prints a given vector into standard output.
 *  
 *  @param vec The vector to be printed.
 *  @param delim The delimiter to be printed after values.
 */
template<class T>
void PrintVector(const std::vector<T> & vec, bool space=true) {

    
    // if vector is empty, print out that the list is empty.
    if (vec.empty()) {
        std::cout << "List is Empty" << std::endl;
    

    // if not, print out delimited values.
    } else {
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec.at(i);
            if (space) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}


/**
 *  Uses binary search with O(logn) time complexity to find the leftmost
 *  index that is larger than or equal to value. Input vector must be sorted.
 *  
 *  @param piles The input vector to be searched.
 *  @param card The input value to be "placed."
 *  @return Value in interval [0, piles.size()]. piles.size() means that a new pile must be made.
 */
template<class T>
size_t LeftmostSolitairePlacement(const std::vector<T> & piles, T card) {


    // binary search with [0, piles.size()] as bounds.
    // we do `piles.size()` because we want the ability for this function to return
    // a case where a new pile must be made.
    size_t l = 0, r = piles.size();


    // iterate until `r` "closes in on" `l`.
    while (l < r) {

        
        // find the averge of `l` and `r` to find the middle.
        size_t m = (l + r) / 2;


        // if the card at the middle is not valid for placement, move `l` one past middle.
        if (piles[m] < card) {
            l = m + 1;
        

        // else, move `r` (right bound) to middle.
        } else {
            r = m;
        }
    }


    // `l` because either the minumum available index or piles.size() which means
    // that a new pile must be made.
    return l;
}


/**
 *  Overwrites element in vector at index with another. If index is equal
 *  to the size of the vector (just out of bounds), the vector is extended.
 * 
 *  @param vec The vector in question.
 *  @param index The index to be overwritten or extended to.
 *  @param elem The element to be inserted.
 */
template<class T>
void OverwriteOrAppend(std::vector<T> & vec, size_t index, T elem) {
    
    // if index is one index out of bounds, create a new pile.
    if (index == vec.size()) {
        vec.push_back(elem);
    
    // else, replace the element at index with `elem`.
    } else {
        vec.at(index) = elem;
    }
}


/**
 *  Finds the length of the longest increasing subsequence, inspired by patience
 *  sorting. Take out a deck of cards and deal them one-by-one following these rules:
 *      - A card must be placed on a card of equal or greater value.
 *      - A card can be placed in a new pile (to the right).
 *  Notice that the bottom-most cards are always in increasing order from left to right.
 *  An upshot of this whole process is that the number of piles corresponds to the longest
 *  increasing subsequence. The following algorithm implements this precisely.
 *  
 *  Note: Since a binary search O(logn) is done n times, this algorithm runs in O(nlogn) time.
 *  And since the maximum length for an increasing subsequence is limited by the length of the input
 *  vector, this algorithm has O(n) space complexity.
 *  
 *  Note 2: This algorithm looks for STRICTLY INCREASING subsequences. i.e. ['e', 'e', 'e'] would
 *  return a maximum increasing subsequence length of 1.
 *  
 *  @param deck The vector in which the length of the longest increasing subsequence will be found.
 *  @return An integer denoting the length of the longest increasing subsequence in the given vector.
 */
template<class T>
size_t LongestIncreasingSubsequenceLength(const std::vector<T> & deck) {

    
    // store the smallest in each pile.
    std::vector<T> piles;
    for (T card : deck) {
        
        // find leftmost valid pile.
        size_t index = LeftmostSolitairePlacement(piles, card);
        
        // place card on pile or create pile if it does not exist.
        OverwriteOrAppend(piles, index, card);
    }


    // piles.size() is the length of the maximum increasing subsequence.
    // because, if you look at one pile, cards that are stacked on top are
    // newer with smaller value. ergo, an increasing subsequence can only
    // use one card from each pile.
    return piles.size();
}