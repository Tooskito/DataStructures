// @author      Jonathan Abbott
// @date        Oct 4th, 2020
// @desc        This file includes the implementation details to Huffman-encode a string.


#ifndef HUFFMAN_H
#define HUFFMAN_H


#include <iostream> // std::cout, std::endl
#include <string> // std::string
#include <unordered_map> // std::unordered_map
#include "Priority.h" // Priority<T>
#include "PriorityQueue.h" // PriorityQueue<T>


// Namespace to hold all of the relevant functions and classes so that we can have short function names.
namespace Huffman {
    

    // Simply a tree-node that holds a character, could have been a struct, really.
    class Node {


        char mValue;
        Node* mLeft;
        Node* mRight;
    

    public:
        

        // Default constructor and other constructors.
        Node() : mValue(), mLeft(nullptr), mRight(nullptr) {}
        Node(char inValue)
            : mValue(inValue), mLeft(nullptr), mRight(nullptr) {}
        Node(char inValue, Node* inLeft, Node* inRight)
            : mValue(inValue), mLeft(inLeft), mRight(inRight) {}
        

        // Copy constructor.
        Node(const Node& other)
            : mValue(other.mValue), mLeft(other.mLeft), mRight(other.mRight) {}
        

        // Destructor, since this class has pointer members.
        ~Node() {
            if (mLeft != nullptr) delete mLeft;
            if (mRight != nullptr) delete mRight;
        }


        // Getter methods, remember how we prefixed member variables with `m` for these short names.
        char value() { return mValue; }
        Node* left() { return mLeft; }
        Node* right() { return mRight; }


        // Copy assignment operator, necessary for rule-of-three compliance.
        Node& operator=(const Node& assign) {
            if (this != &assign) {
                mValue = assign.mValue;
                mLeft = assign.mLeft;
                mRight = assign.mRight;
            }
            return *this;
        }
    };


    /**
     *  Reads the Huffman-Codes from a Huffman-Tree into a std::unordered_map<char, std::string>.
     *  @param root A pointer to the root of the Huffman-Tree.
     *  @param map A reference to the std::unordered_map where the encodings will be stored.
     *  @param enc Optional parameter that is used internally to recursively trace the tree.
     */
    void Read(Node* root, std::unordered_map<char, std::string>& map, std::string enc="") {
        if (root->left() == nullptr and root->right() == nullptr) {
            map[root->value()] = enc;
        } else {
            Read(root->left(), map, enc + "0");
            Read(root->right(), map, enc + "1");
        }
    }


    /**
     *  Decodes a Huffman-Code sequence into a string and prints it.
     *  @param encstr The encoded Huffman-Code sequence as a string.
     *  @param encmap The hashmap used to encode the `encstr`.
     */
    void Decode(const std::string& encstr, const std::unordered_map<char, std::string>& encmap) {
        

        
        /* Reverse encoding map. We can do this because both "sides" (sets?) are unique. */
        std::unordered_map<std::string, char> decmap;
        for (
            std::unordered_map<char, std::string>::const_iterator it = encmap.begin();
            it != encmap.end(); ++it
        ) {
            decmap[it->second] = it->first;
        }


        /* Decode the string by chunks. */
        std::string decstr;
        unsigned int chunkbegin = 0;
        for (unsigned int i = 1; i <= encstr.size(); ++i) {
            if (decmap.find(encstr.substr(chunkbegin, i - chunkbegin)) != decmap.end()) {
                decstr += decmap[encstr.substr(chunkbegin, i - chunkbegin)];
                chunkbegin = i;
            }
        }

        std::cout << "The decoded string is:" << std::endl;
        std::cout << decstr << std::endl << std::endl;
    }


    /**
     *  Takes a string, prints out the Huffman-Codes for it, the Huffman-Code encoding of it, shows some
     *  statistics about the compression, and decodes the encoded string to the original.
     *  @param str The string to do all this to.
     */
    void Encode(const std::string& str) {


        /* Print original string. */
        std::cout << "Original string:" << std::endl;
        std::cout << str << std::endl << std::endl;


        /* Count frequencies of characters in string. */
        std::unordered_map<char, unsigned int> freq;
        for (const char& c : str) freq[c] += 1;
        if (freq.size() == 1) {
            std::cerr << "Input string must have more than one unique character." << std::endl;
            return;
        }

    
        /* Initialize priority queue. */
        PriorityQueue<Node*> pq;
        for (
            std::unordered_map<char, unsigned int>::iterator it = freq.begin();
            it != freq.end(); ++it
        ) {
            pq.push( Priority<Node*>{new Node(it->first), it->second} );
        }


        /* Build Huffman-Tree. */
        Priority<Node*> one, two, three;
        while (pq.size() > 1) {
            one = pq.top(); pq.pop();
            two = pq.top(); pq.pop();
            three = Priority<Node*>{
                new Node('\0', one.value(), two.value()),
                one.priority() + two.priority()
            };
            pq.push(three);
        }

        
        /* Insert Huffman-Codes into hashmap and free Huffman-Tree. */
        Node* root = pq.top().value(); pq.pop();
        std::unordered_map<char, std::string> enc;
        Read(root, enc);
        delete root;


        /* Now, print hashmap. */
        std::cout << "Huffman-Codes are:" << std::endl;
        for (
            std::unordered_map<char, std::string>::iterator it = enc.begin();
            it != enc.end(); ++it
        ) {
            std::cout << it->first << " -> " << it->second << std::endl;
        }
        std::cout << std::endl;


        /* Now, print encoded message. */
        std::string encstr;
        for (const char& c : str) {
            encstr += enc[c];
        }
        std::cout << "The encoded message is:" << std::endl;
        std::cout << encstr << std::endl;


        /* Print statistics about encoding. */
        unsigned int origbytes = (unsigned int)str.size() * 8;
        unsigned int finalbytes = (unsigned int)encstr.size();
        double savings = (1 - (double)finalbytes / origbytes) * 100;

        std::cout << std::endl;
        std::cout << origbytes << " bits (in ASCII) -> " << finalbytes << " bits" << std::endl;
        std::cout << "That is a " << savings << "% reduction!" << std::endl;
        std::cout << std::endl;

        Decode(encstr, enc);
    }
}

#endif