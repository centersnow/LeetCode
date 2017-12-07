//
//  Solution.cpp
//  LeetCode
//


#include "Solution.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

class Solution {
public:       
    bool areSentencesSimilar(std::vector<std::string>& words1, std::vector<std::string>& words2, std::vector<std::pair<std::string, std::string>> pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        std::map<std::string, std::set<std::string>> m;
        for (auto p : pairs) {
            m[p.first].insert(p.second);
            m[p.second].insert(p.first);
        }
        
        for (size_t i = 0; i < words1.size(); i++) {
            if (words1[i] == words2[i]) {
                continue;
            }
            if (m.count(words1[i]) == 0 || m[words1[i]].count(words2[i]) == 0) {
                  return false;
            }
        }
        return true;
    }
};
