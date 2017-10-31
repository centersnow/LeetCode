//
//  Solution.cpp
//  LeetCode
//

#include "Solution.hpp"
#include <iostream>
#include <vector>
#include <map>

class Solution {
private:
    bool canPartitionKSubsets(std::vector<int>& nums, int k, std::vector<bool> visited,
                              size_t index, int sum, int size, int target) {
        if (k == 1) {
            return true;
        }
        if (sum > target) {
            return false;
        }
        if (sum == target && size > 0) {
            return canPartitionKSubsets(nums, k - 1, visited, 0, 0, 0, target);
        }
        for (size_t i = index; i < nums.size(); i++) {
            if (visited[i] == false) {
                visited[i] = true;
                if (canPartitionKSubsets(nums, k, visited, i + 1, sum + nums[i], size + 1, target) == true) {
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }
    
public:
    bool canPartitionKSubsets(std::vector<int>& nums, int k) {
        if (k <= 0) {
            return false;
        }
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        std::vector<bool> visited(nums.size(), false);
        return canPartitionKSubsets(nums, k, visited, 0, 0, 0, target);
    }
};
