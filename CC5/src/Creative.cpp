#include <iostream>
#include <string>
#include <unordered_map>
#include "../include/Priority.h"
#include "../include/SorDLList.h"
#include "../include/Huffman.h"

int main() {
    Priority<char> myPrio('A', 5);
    PriorityNode<char> myTree(myPrio, nullptr, nullptr);

    std::string test = "Huffman coding is a data compression algorithm.";
    std::unordered_map<char, unsigned int> map;
    for (const char& c : test) map[c] += 1;

    SorDLList<PriorityNode<char>*> list;
    for (std::unordered_map<char, unsigned int>::iterator it = map.begin(); it != map.end(); ++it) {
        Priority<char> prio(it->first, it->second);
        PriorityNode<char>* pnode = new PriorityNode<char>(prio, nullptr, nullptr);
        list.Insert(pnode);
    }
    std::cout << list << std::endl;
    return 0;
}