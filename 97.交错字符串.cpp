/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        if((n1 + n2) != n3)return false;

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        dp[0][0] = 1;

        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                int p = i + j - 1;
                if(i > 0)
                {
                    dp[i][j] |= (dp[i-1][j] && s1[i-1] == s3[p]);
                }
                if(j > 0)
                {
                    dp[i][j] |= (dp[i][j-1] && s2[j-1] == s3[p]);
                }
            }
        }
        return dp[n1][n2] == 1;
    }

    bool isInterleave2(string s1, string s2, string s3) {
        
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        if((n1 + n2) != n3)return false;
        if(n1 == 0) return s2 == s3;
        if(n2 == 0) return s1 == s3;
        return backtrack(s1, s2, s3, 0, 0, 0);
    }

    bool backtrack(string &s1, string &s2, string &s3, int i, int j, int r)
    {
        if(i == s1.size() && j == s2.size() && r == s3.size())return true;
        
        if(i == s1.size())
        {
            if(s2[j] == s3[r])
                return backtrack(s1, s2, s3, i, j+1, r+1);
            else
                return false;
        }
        if(j == s2.size())
        {
            if(s1[i] == s3[r])
                return backtrack(s1, s2, s3, i+1, j, r+1);
            else return false;
        }

        if(s1[i] == s3[r] && s2[j] != s3[r])
        {
            return backtrack(s1, s2, s3, i+1, j, r+1);
        }else if(s2[j] == s3[r] && s1[i] != s3[r])
        {
            return backtrack(s1, s2, s3, i, j+1, r+1);
        }else if(s1[i] == s3[r] && s2[j] == s3[r])
        {   
            bool ans = false;
            if(i < s1.size()-1)
            {
                ans = backtrack(s1, s2, s3, i+1, j, r+1);
            }
            if(j < s2.size()-1)
            {
                ans = ans || backtrack(s1, s2, s3, i, j+1, r+1);
            }
            return ans;
        }else{
            return false;
        }
        return true;
    }

};
// @lc code=end

