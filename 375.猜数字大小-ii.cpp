/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int getMoneyAmount(int n) {
       vector<vector<int>> dp(n+1, vector<int>(n+1,0));
       for(int len=2;len<=n;len++)
       {
           for(int start=1;start<=n-len+1;start++)
           {
               int minres = INT_MAX;
               for(int piv=start;piv<start+len-1;piv++)
               {
                   int res = piv + max(dp[start][piv-1], dp[piv+1][start+len-1]);
                   minres = min(res, minres);
               }
               dp[start][start+len-1] = minres;
           }

       }
        return dp[1][n];
    }

};
// @lc code=end

