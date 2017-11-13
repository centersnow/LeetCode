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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    std::vector<ListNode*> splitListToParts(ListNode* root, int k) {
        std::vector<ListNode*> res;
        int len = 0;
        ListNode* head = root;
        while (head != nullptr) {
            head = head->next;
            len++;
        }
        
        if (len <= k) {
            int i = 0;
            head = root;
            while (i < len) {
                res.emplace_back(head);
                
                ListNode* temp = head;
                head = head->next;
                temp->next = nullptr;
                i++;
            }
            while (i < k) {
                res.emplace_back(nullptr);
                i++;
            }
        } else {
            int each = len / k;
            int count = len % k;
            head = root;
            while (head != nullptr) {
                res.emplace_back(head);
                int j = 0;
                while (j < each - 1) {
                    head = head->next;
                    j++;
                }
                if (count > 0) {
                    head = head->next;
                    count--;
                }
                ListNode* temp = head;
                head = head->next;
                temp->next = nullptr;
            }
        }
        
        return res;
    }
};
