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
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        std::vector<std::string> res;
        std::unordered_set<std::string> visited;
        std::queue<std::string> q;
        bool valid = false;
        q.push(s);
        
        while (q.empty() == false) {
            std::string temp = q.front();
            q.pop();
            
            if (isValid(temp) == true) {
                res.emplace_back(temp);
                valid = true;
            } else if (valid == false) {
                for (size_t i = 0; i < temp.length(); i++) {
                    if (temp[i] != '(' && temp[i] != ')') {
                        continue;
                    }
                    std::string next = temp.substr(0, i) + temp.substr(i + 1);
                    if (visited.count(next) == 0) {
                        visited.emplace(next);
                        q.push(next);
                    }
                }
            }
        }
        
        return res;
    }

private:
    bool isValid(std::string s) {
        int count = 0;
        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                count++;
            } else if (s[i] == ')') {
                count--;
            }
            if (count < 0) {
                return false;
            }
        }
        return count == 0;
    }
};
