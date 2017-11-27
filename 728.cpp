//
//  Solution.cpp
//  LeetCode
//


#include "Solution.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_set>
#include <queue>

class Solution {
public:
    std::vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> res;
        
        for (int i = left; i <= right; i++) {
            int j = i;
            while (j > 0) {
                if (j % 10 == 0 || i % (j % 10) != 0) {
                    break;
                }
                j /= 10;
            }
            if (j == 0) {
                res.emplace_back(i);
            }
        }
        
        return res;
    }
};
