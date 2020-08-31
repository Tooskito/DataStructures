/**
 *  @author Jonathan Abbott
 *  @date   Aug 31, 2020
 *  
 *  This file includes the implementation details for my Anagram checker for `Lab3` in CSE 20312.
 */


#include <string>           // std::string
#include <unordered_map>    // std::unordered_map


// Standard define guards against multiple definition.
#ifndef LAB3_ANAGRAM_H_
#define LAB3_ANAGRAM_H_


// Put into `Anagram` namespace for clarity.
namespace Anagram {


    /**
     *  Checks if two given strings are anagrams of each other.
     *  
     *  @param s The first string.
     *  @param t The second string.
     *  @return true if the given strings are anagrams of each other.
     */
    bool Check(const std::string & s, const std::string & t) {


        // Create a hashmap to store all of the characters in `s` that must be fulfilled by `t`.
        std::unordered_map<char, int> map;


        // Chars in `s` are filed into hashmap.
        for (const auto & c : s)
            map[c]++;
        

        // `t` must match the count i.e. "remove them from the hashmap.""
        for (const auto & c : t)
            map[c]--;
        

        // If there are remnants leftover in the hashmap that are not 0 (i.e. keys with values > 0
        // are those that appear in s and not in t, and keys with values < 0 are those that
        // appear in t and not in s), then that means `s` and `t` are not anagrams.
        for (const auto & e : map)
            if (e.second != 0)
                return false;
        

        // If the above didn't catch, that means `s` and `t` satisfy each other.
        return true;
    }
}


/**
 *  Prints two given strings and the result of their anagram test.
 *  
 *  @param s The first string.
 *  @param t The second string.
 */
void AnagramTest(const std::string & s, const std::string & t) {
    std::cout << "String #1:\t" << s << std::endl;
    std::cout << "String #2:\t" << t << std::endl;

    std::cout << "Result:\t\t";
    std::cout << (Anagram::Check(s, t) ? "Are Anagrams" : "Are NOT Anagrams");
    std::cout << std::endl;
}


#endif