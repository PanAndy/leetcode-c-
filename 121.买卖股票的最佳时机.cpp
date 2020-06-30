/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0)return 0;
        vector<vector<int> > dp(n, vector<int>(2, 0));
        for(int i=0;i<n;i++)
        {
            if(i - 1 == -1)
            {
                dp[i][1] = -prices[i];
                dp[i][0] = 0;
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], -prices[i]);
        }
        return dp[n-1][0];
    }
    // int maxProfit(vector<int>& prices) {
        
    //     int max_p = 0;
    //     int n = prices.size();
    //     if(n<=1)return max_p;
    //     int min_p = prices[0];

    //     for(int i=1;i<n;++i)
    //     {
    //         if(prices[i]>min_p)
    //         {
    //             max_p = max(max_p, prices[i]-min_p);
    //         }else{
    //             min_p = prices[i];
    //         }
    //     }

    //     return max_p;
    // }
};
// @lc code=end

