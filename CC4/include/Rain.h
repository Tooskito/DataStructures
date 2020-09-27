/**
 *  @author Jonathan Abbott
 *  @date   September 27, 2020
 *  Contains the implementation for my solution for Prob2 of CC4 for CSE 20312.
 */
#ifndef RAIN_H
#define RAIN_H

#include <iostream> // std::ostream
#include <vector> // std::vector
// Typedef for quality-of-life.
typedef std::vector<int> v_t;

// So that std::cout << v_t prints out all integers in vector.
std::ostream& operator<< (std::ostream& os, const v_t& vec) {
    os << "( ";
    for (const int& val : vec)
        os << val << " ";
    os << ")" << std::endl;
    return os;
}

// To keep solution compartmentalized.
namespace Rain {
    /**
     *  Given a vector of heights, return the (int) amount of water that can be trapped in its valleys.
     */
    int Trap(const v_t& vec){
        int ans = 0, right = (int)vec.size()-1, left = 0, rmax = 0, lmax = 0;
        while (left < right) {
            // If height of left is less than height of right.
            if (vec.at(left) < vec.at(right)) {
                // If height of left is a new max, set the left max.
                if (vec.at(left) >= lmax) lmax = vec.at(left++);
                // Else, water can be deposited.
                else ans += lmax - vec.at(left++);
            } else {
                // If height of right is a new max, set the right max.
                if (vec.at(right) >= rmax) rmax = vec.at(right--);
                // Else, water can be deposited.
                else ans += rmax - vec.at(right--);
            }
        }
        return ans;
    }
}

#endif