/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n==0)return 0;

        vector<int> dp(n, 0);
        for(int i=0;i<n;i++)
        {
            if(s[i]!='0'){
                dp[i]=1;
                break;
            }
        }
        for(int i=1;i<n;i++)
        {
            if(s[i]!='0')
                dp[i] = dp[i-1];
            int num = 10 * (s[i-1] - '0') + (s[i] - '0');
            if(num>=10 && num<=26){
                dp[i] += (i-2 >=0 ? dp[i-2] : 1);
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

