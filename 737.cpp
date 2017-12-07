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
private:
    std::string find(std::string s, std::map<std::string, std::string>& m) {
        if (m.count(s) == 0) {
            m[s] = s;
        }
        while (s != m[s]) {
            s = m[s];
        }
        return s;
    }        

public:        
    bool areSentencesSimilarTwo(std::vector<std::string>& words1, std::vector<std::string>& words2, std::vector<std::pair<std::string, std::string>> pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        
        std::map<std::string, std::string> id;
        for (auto p : pairs) {
            std::string p1 = find(p.first, id);
            std::string p2 = find(p.second, id);
            if (p1 != p2) {
                id[p1] = p2;
            }
        }
        
        
        for (size_t i = 0; i < words1.size(); i++) {
            if ((words1[i] != words2[i]) && (find(words1[i], id) != find(words2[i], id))) {
                return false;
            }
        }
        return true;
    }
};
