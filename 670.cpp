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

class Solution {
public:
    int maximumSwap(int num) {
        std::string s = std::to_string(num);
        int res = num;
        
        for (int i = 0; i < s.length() - 1; i++) {
            for (int j = i + 1; j < s.length(); j++) {
                if (s[i] < s[j]) {
                    std::string t = s;
                    t[i] = s[j];
                    t[j] = s[i];
                    
                    int temp = stoi(t);
                    res = std::max(res, temp);
                }
            }
        }
        return res;
    }
};
