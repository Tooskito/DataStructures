/**
 *  @author Jonathan Abbott
 *  @date   Sep 7th, 2020
 * 
 *  Includes definition of `MergeIntervals` as well as some quality-of-life improvements for
 *  `Lab4` for CSE 20312 such as: overloaded std::ostream operators for std::vector and std::pair,
 *  and a testing method `DoTest`.
 */


#include <iostream>     // std::cout, std::endl
#include <vector>       // std::vector
#include <utility>      // std::pair
#include <algorithm>    // std::sort


// Standard include guards against multiple definition.
#ifndef MERGEINT_H_ /* `MergeInt.h` */
#define MERGEINT_H_


// For quality-of-life and readability. std::vector<std::pair<int, int>> vs. interval_list_t
typedef std::pair<int, int> interval_t;
typedef std::vector<interval_t> interval_list_t;


// Overloaded operator for i.e. std::cout << std::vector
template<class T, class S>
std::ostream& operator<< (std::ostream& os, const std::pair<T, S>& p)
{
    os << "Pair(";
    os << p.first << ", ";
    os << p.second << ")";
    return os;
}


// Overloaded operator for i.e. std::cout << std::pair
template<class T>
std::ostream& operator<< (std::ostream& os, const std::vector<T>& v)
{
    os << "Vector( ";
    for (const auto& a : v)
        os << a << " ";
    os << ")";
    return os;
}


// Defined namespace for non-ambiguity from outside this file.
namespace MergeIntervals {


    /**
     *  Given a list of intervals, sorts and merges any overlapping intervals and returns the result.
     *  @param intervals The list of interval_t's.
     */
    void Do(interval_list_t& intervals)
    {

        // Test if there's at least one interval in the list.
        if (intervals.size() <= 0)
            return;
        
        // Sort in increasing order by first value in interval pair.
        std::sort(intervals.begin(), intervals.end());

        
        // Set the stack pointer to 0, and iterate from 1 onwards.
        int stack_top_p = 0;
        for (int iter = 1; iter < (int)intervals.size(); ++iter)
        {

            // Nab the stack_top by reference so we can change it easily.
            interval_t& stack_top = intervals.at(stack_top_p);

            // True in i.e. [1, 3] [4, 6]
            if (stack_top.second < intervals.at(iter).first)
            {

                // Push iter interval to top of stack.
                ++stack_top_p;
                intervals.at(stack_top_p) = intervals.at(iter);
            }

            // True in i.e. [1, 5] [3, 7]
            else if (stack_top.second < intervals.at(iter).second)
            {

                // From example above, becomes: [1, 7] [3, 7]
                stack_top.second = intervals.at(iter).second;
            }
        }

        
        // If stack didn't consume the whole vector.
        if (stack_top_p + 1 < (int)intervals.size())
        {

            // Then erase all the elements left after the stack.
            intervals.erase(intervals.begin() + stack_top_p + 1, intervals.end());
        }
    }


    /**
     *  Given a list of intervals, prints before-after of `MergeIntervals`.
     *  @param ilt The list of interval_t's to print.
     */
    void Test(interval_list_t& ilt)
    {
        std::cout << std::endl;
        std::cout << "Initial interval list:\t\t" << ilt << std::endl;
        Do(ilt);
        std::cout << "Final interval list:\t\t" << ilt << std::endl;
    }
}


#endif /* `MergeInt.h` */