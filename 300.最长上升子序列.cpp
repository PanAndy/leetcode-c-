/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += 1;
        }
        int ans = 0;
        for(int i = 0; i < dp.size(); ++i)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

