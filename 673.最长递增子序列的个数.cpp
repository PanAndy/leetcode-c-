/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j])
                {
                    if(dp[j] >= dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }else if(dp[j]+1 == dp[i]){
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        int longest = 0, ans = 0;
        for(int l : dp){
            longest = max(longest, l);
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]==longest)
            {
                ans += cnt[i];
            }
        }
        return ans;
    }
};
// @lc code=end

