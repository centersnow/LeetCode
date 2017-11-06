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
    std::string longestWord(std::vector<std::string>& words) {
        std::string res;
        std::unordered_set<std::string> s;
        
        sort(words.begin(), words.end());
        
        for (std::string t : words) {
            if (t.length() == 1 || s.count(t.substr(0, t.length() - 1)) > 0) {
                s.emplace(t);
                if (t.length() > res.length()) {
                    res = t;
                }
            }
        }
        
        return res;
    }
};
