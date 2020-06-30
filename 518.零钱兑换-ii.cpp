/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        // for(int i=0;i<coins.size();++i)
        // {
        //     dp[coins[i]] = 1;
        // }
        // for(int i=1;i<=amount;++i)
        // {
        //     for(int j=0;j<coins.size();++j)
        //     {
        //         if(i-coins[j]>=0)
        //         {
        //             dp[i] = dp[i] + dp[i-coins[j]];
        //         }
        //     }
        // }
        dp[0] = 1;
        for(int j=0;j<coins.size();++j)
        {
            for(int i=coins[j];i<=amount;++i)
            {
                dp[i] = dp[i] + dp[i-coins[j]];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

