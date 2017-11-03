//
//  Solution.cpp
//  LeetCode
//
//  Created by Changlong Chen on 10/18/17.
//  Copyright © 2017 Changlong Chen. All rights reserved.
//

#include "Solution.hpp"
#include <iostream>
#include <vector>
#include <map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int res = 0;
        int index = 0;
        int product = 1;
        
        for (size_t i = 0; i < nums.size(); i++) {
            product *= nums[i];
            while (product >= k) {
                product /= nums[index];
                index++;
            }
            res += (i - index + 1);
        }
        return res;
    }
};
