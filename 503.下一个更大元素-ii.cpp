/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        stack<int> s;

        for(int i=2*n-1;i>=0;i--)
        {
            while(!s.empty() && s.top() <= nums[i%n])
                s.pop();
            res[i%n] = s.empty() ? -1 : s.top();
            s.push(nums[i%n]);
        }
        return res;
    }
};
// @lc code=end

