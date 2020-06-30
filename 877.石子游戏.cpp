/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

// @lc code=start

#include<iostream>
#include<vector>

using namespace std;

typedef pair<int,int> PII;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int k = piles.size();
        vector<vector<PII> > dp(k, vector<PII>(k, PII(0, 0)));
        for(int i=0;i<k;i++)
        {
            dp[i][i].first = piles[i];
            dp[i][i].second = 0;
        }

        for(int i=k-2;i>=0;--i)
        {
            for(int j=i+1;j<k;++j)
            {
                // 先手和后手的互换原理
                // 强大啊
                // 这在博弈问题里应该是一种常见的模型
                int c_l = piles[i] + dp[i+1][j].second;
                int c_r = piles[j] + dp[i][j-1].second;
                if(c_l>c_r)
                {
                    dp[i][j].first = c_l;
                    dp[i][j].second = dp[i+1][j].first;
                }else{
                    dp[i][j].first = c_r;
                    dp[i][j].second = dp[i][j-1].first;
                }
            }
        }
        return dp[0][k-1].first > dp[0][k-1].second;

    }
};
// @lc code=end

