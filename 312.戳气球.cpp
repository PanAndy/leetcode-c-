/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> point(n+2, 1);
        for(int i=0;i<n;++i){
            point[i+1] = nums[i];
        }
        vector<vector<int> > dp(n+2, vector<int>(n+2, 0));

        for(int i=n;i>=0;i--)
        {
            for(int j=i+1;j<n+2;j++)
            {
                for(int k=i+1;k<j;k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k] + point[i]*point[j]*point[k] + dp[k][j]);
                }
            }
        }
        return dp[0][n+1];
    }
};
// @lc code=end

