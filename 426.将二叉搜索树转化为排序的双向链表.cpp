/*
 * @lc app=leetcode.cn id=426 lang=cpp
 *
 * [426] 将二叉搜索树转化为排序的双向链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

// struct Node {
//     Node* left;
//     Node* right;
// };

class Solution {
public:
    Node *pre = nullptr, *head = nullptr;

    void traversal(Node *node) {
        if (node->left) {
            traversal(node->left);
        }

        if (pre != nullptr) {
            node->left = pre;
            pre->right = node;
        } else {
            head = node;
        }
        pre = node;

        if (node->right) {
            traversal(node->right);
        }
    }

    Node *treeToDoublyList(Node *root) {
        // 处理单个节点,而非子节点
        if (root == nullptr) {
            return root;
        }
        traversal(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};

// @lc code=end
