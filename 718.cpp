//
//  Solution.cpp
//  LeetCode
//

#include "Solution.hpp"
#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int findLength(std::vector<int>& A, std::vector<int>& B) {
        int res = 0;
        std::vector<std::vector<int>> f(A.size() + 1, std::vector<int>(B.size() + 1, 0));
        
        for (size_t i = 1; i <= A.size(); i++) {
            for (size_t j = 1; j <= B.size(); j++) {
                if (A[i - 1] == B[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                    res = std::max(res, f[i][j]);
                }
            }
        }
        return res;
    }
};
