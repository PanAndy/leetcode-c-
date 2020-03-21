/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp=nums[0];
        int res = dp;
        for(int i=1;i<nums.size();++i){
            dp = max(dp+nums[i],nums[i]);
            res = max(res,dp);
        }
        return res;
    }
};
// @lc code=end

