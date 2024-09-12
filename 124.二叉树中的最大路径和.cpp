/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(TreeNode *root, int &ans) {
        if (root == nullptr) {
            return 0;
        }
        int leftBS = maxSum(root->left, ans);
        int rightBS = maxSum(root->right, ans);
        ans = max({ans, leftBS + rightBS + root->val});
        return max(max(leftBS, rightBS) + root->val, 0);
    }

    int maxPathSum(TreeNode *root) {
        int ans = INT_MIN;
        maxSum(root, ans);
        return ans;
    }
};

// @lc code=end
