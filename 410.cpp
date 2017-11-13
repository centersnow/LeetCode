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
    int splitArray(std::vector<int>& nums, int m) {
        size_t len = nums.size();
        std::vector<int> pre(len + 1, 0);
        std::vector<std::vector<int>> f(len + 1, std::vector<int>(m + 1, 0));
        
        for (size_t i = 0; i < len; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        
        for (size_t i = 1; i <= len; i++) {
            f[i][1] = pre[i];
        }
        
        for (int j = 1; j <= m; j++) {
            f[1][j] = pre[1];
        }
        
        for (size_t i = 2; i <= len; i++) {
            for (int j = 2; j <= m; j++) {
                f[i][j] = INT_MAX;
                for (size_t k = 1; k < i; k++) {
                    int temp = std::max(pre[i] - pre[k], f[k][j - 1]);
                    f[i][j] = std::min(f[i][j], temp);
                }
            }
        }
        return f[len][m];
    }
};
