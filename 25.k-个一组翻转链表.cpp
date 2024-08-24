/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

// struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *cursor = head;
        for (int i = 0; i < k; ++i) {
            if (cursor == nullptr) {
                return head;
            }
            cursor = cursor->next;
        }
        ListNode *cur = head, *pre = nullptr, *nxt = nullptr;
        for (int i = 0; i < k; ++i) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        head->next = reverseKGroup(cur, k);
        return pre;
    }
};

// @lc code=end
