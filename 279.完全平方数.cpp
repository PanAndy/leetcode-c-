/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        int mqi = (int)sqrt(n) + 1;
        vector<int> square(mqi, 0);
        for(int i=1;i<mqi;++i)
        {
            square[i] = i * i;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<mqi;++j)
            {
                if(i<square[j])
                {
                    break;
                }
                dp[i] = min(dp[i], dp[i - square[j]]+1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

