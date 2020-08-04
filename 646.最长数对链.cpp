/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n==0)return 0;

        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> dp(n, 1);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
};
// @lc code=end

