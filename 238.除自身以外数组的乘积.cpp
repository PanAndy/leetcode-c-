/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums);
        int n = nums.size();
        for(int i=0;i<n;++i)
        {
            ans[i] = 1;
        }

        for(int i=1;i<n;++i)
        {
            ans[i] = ans[i-1]*nums[i-1];
        }
        int temp = 1;
        for(int i=n-2;i>=0;--i)
        {
            temp = temp*nums[i+1];
            ans[i] = ans[i] * temp;
        }
        return ans;
    }
};
// @lc code=end

