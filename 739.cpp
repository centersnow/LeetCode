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
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int size = static_cast<int>(temperatures.size());
        std::vector<int> res(size, 0);
        std::stack<int> s;
        
        for (int i = 0; i < size; i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int idx = s.top();
                s.pop();
                res[idx] = i - idx;
            }
            s.push(i);
        }
        
        return res;
    }
};
