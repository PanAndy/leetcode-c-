/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0)return 0;
        if(k>n/2)
        {
            vector<vector<int>> dp(n,vector<int>(2, 0));

            for(int i=0;i<n;i++)
            {
                if(i-1 == -1){
                    dp[0][0] = 0;
                    dp[0][1] = -prices[0];
                    continue;
                }
                // int temp = dp[i][0];
                dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
                dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
            }
            return dp[n-1][0];
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, 0)));
        for(int i=0;i<n;i++)
        {
            for(int K=1;K<=k;K++)
            {
                if(i-1 == -1)
                {
                    dp[i][K][0] = 0;
                    dp[i][K][1] = -prices[0];
                    continue;
                }
                dp[i][K][0] = max(dp[i-1][K][0], dp[i-1][K][1]+prices[i]);
                dp[i][K][1] = max(dp[i-1][K][1], dp[i-1][K-1][0]-prices[i]);
            }
        }
        return dp[n-1][k][0];
    }
};
// @lc code=end

