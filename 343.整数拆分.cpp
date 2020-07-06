/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3;i<=n;i++)
        {
            for(int j=1;j<=i-1;++j)
            {
                dp[i] = max(dp[i], max(j*(i-j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};
// @lc code=end

