/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        // for(int i=0;i<coins.size();++i)
        //     if(coins[i]<=amount)
        //         dp[coins[i]]=1;

        for(int i=1;i<=amount;++i)
        {
            int m = INT_MAX;
            for(int j=0;j<coins.size();++j)
            {
                if(i - coins[j] < 0)
                {
                    continue;
                }
                if(dp[i - coins[j]] == -1)
                    continue;
                m = min(dp[i - coins[j]], m);
            }
            if(m == INT_MAX){
                dp[i] = -1;
                continue;
            }
            dp[i] = m + 1;
        }
        return dp[amount];
    }
};
// @lc code=end

