//
//  Solution.cpp
//  LeetCode
//


#include "Solution.hpp"
#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    bool isOneBitCharacter(std::vector<int>& bits) {
        size_t i = 0;
        while (i < bits.size() - 1) {
            if (bits[i] == 0) {
                i++;
            } else {
                i += 2;
            }
        }
        return i == bits.size() - 1;
    }
};
