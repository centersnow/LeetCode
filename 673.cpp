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
    int findNumberOfLIS(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return static_cast<int>(nums.size());
        }
        std::vector<int> len(nums.size(), 1);
        std::vector<int> count(nums.size(), 1);
        int f = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            for (size_t j = 0; j < i; j++) {
                if (nums[i] > nums[j] && len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                }
            }
            
            int temp = 0;
            for (size_t j = 0; j < i; j++) {
                if (nums[i] > nums[j] && len[j] == len[i] - 1) {
                    temp += count[j];
                }
            }
            count[i] = std::max(count[i], temp);
            f = std::max(f, len[i]);
        }
        int res = 0;
        for (size_t i = 0; i < len.size(); i++) {
            if (len[i] == f) {
                res += count[i];
            }
        }
        return res;
    }
};
