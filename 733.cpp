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
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
        int m = static_cast<int>(image.size());
        int n = static_cast<int>(image[0].size());
        int color = image[sr][sc];
        if (color == newColor) {
            return image;
        }
        std::queue<int> q;
        q.push(sr * n + sc);
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            int i = f / n;
            int j = f % n;
            image[i][j] = newColor;
            if (i - 1 >= 0 && image[i - 1][j] == color) {
                q.push((i - 1) * n + j);
            }
            if (i + 1 < m && image[i + 1][j] == color) {
                q.push((i + 1) * n + j);
            }
            if (j - 1 >= 0 && image[i][j - 1] == color) {
                q.push(i * n + j - 1);
            }
            if (j + 1 < n && image[i][j + 1] == color) {
                q.push(i * n + j + 1);
            }
        }
        return image;
    }
};
