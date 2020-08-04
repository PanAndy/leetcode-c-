/*
 * @lc app=leetcode.cn id=1000 lang=cpp
 *
 * [1000] 合并石头的最低成本
 */

// @lc code=start
class Solution {
public:
    int dp[31][31][31];
    int sum[31];
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if((n-1)%(K-1))return -1;
        if(n < 2)return 0;
        memset(dp, 0x3f, sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            sum[i] = sum[i-1] + stones[i-1];
            dp[i][i][1] = 0;
        }

        for(int len = 2; len <= n; len++)
        {
            for(int i=1;i<=n-len+1;i++)
            {
                int j = i + len - 1;
                for(int k=2;k<=K;k++)
                {
                    for(int p = i;p<j;p++)
                    {
                        dp[i][j][k] = min(dp[i][j][k], dp[i][p][k-1] + dp[p+1][j][1]);
                    }
                }
                dp[i][j][1] = min(dp[i][j][1], dp[i][j][K] + sum[j] - sum[i-1]);
            }
        }
        return dp[1][n][1];
    }
};
// @lc code=end

