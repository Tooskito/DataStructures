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
 */
template<class T>
void PrintVector(const std::vector<T> & vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;
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
int LeftmostSolitairePlacement(const std::vector<T> & piles, T card) {
    int l = 0, r = piles.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (piles[m] < card) {
            l = m + 1;
            // not "l = m" because we don't care about piles[m] if it's < card.
        } else {
            r = m;
            // not "r = m - 1" because we care if piles[m] >= card.
        }
    }
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
void OverwriteOrAppend(std::vector<T> & vec, int index, T elem) {
    if (index == vec.size()) {
        vec.push_back(elem);
    } else {
        vec.at(index) = elem;
    }
}


/**
 *  Finds the length of the longest increasing subsequence, inspired by patience
 *  sorting. Take out a deck of cards and sort them one-by-one following these rules:
 *      - A card must be placed on a card of equal or greater value.
 *      - A card can be placed in a new pile (to the right).
 *  Notice that the bottom-most cards are always in increasing order from left to right.
 *  An upshot of this whole process is that the number of piles corresponds to the longest
 *  increasing subsequence. The following algorithm implements this precisely.
 *  
 *  Note: Since a binary search O(logn) is done n times, this algorithm runs in O(nlogn) time.
 *  
 *  @param deck The vector in which the length of the longest increasing subsequence will be found.
 *  @return An integer denoting the length of the longest increasing subsequence in the given vector.
 */
template<class T>
int LongestIncreasingSubsequence(const std::vector<T> & deck) {
    std::vector<T> piles;
    for (T card : deck) {
        int index = LeftmostSolitairePlacement(piles, card);
        OverwriteOrAppend(piles, index, card);
    }
    return piles.size();
}

