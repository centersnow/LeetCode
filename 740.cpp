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
    int deleteAndEarn(std::vector<int>& nums) {
        std::vector<int> f(10001, 0);
        std::vector<int> values(10001, 0);
        for (int num : nums) {
            values[num] += num;
        }
        int res = 0;
        f[1] = values[1];
        f[2] = std::max(f[1], values[2]);
        res = std::max(f[1], f[2]);
        for (int i = 3; i < 10001; i++) {
            f[i] = std::max(f[i - 1], f[i - 2] + values[i]);
            res = std::max(res, f[i]);
        }
        return res;
    }
};
