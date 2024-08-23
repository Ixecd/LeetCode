/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        nums.resize(2 * n);
        for (int i = n; i < 2 * n; ++i) {
            nums[i] = nums[i - n];
        }
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < 2 * n; ++i) {
            int ele = nums[i];
            while (!st.empty() && ele > nums[st.top()]) {
                if (st.top() >= n) {
                    st.top() = st.top() - n;
                }
                res[st.top()] = ele;
                st.pop();
            }
            st.push(i);
        }
        return res;
        
    }
};

// @lc code=end
