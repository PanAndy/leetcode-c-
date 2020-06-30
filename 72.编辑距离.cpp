/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:


    int memo[1000][1000];
    int minDistance(string word1, string word2) {
        memset(memo, 0, sizeof(memo));
        return dp(word1,word2,word1.size()-1,word2.size()-1);
    }
    int dp(string word1, string word2, int i, int j)
    {     
        if(i==-1)return j+1;
        if(j==-1)return i+1;
        if(memo[i][j]!=0)return memo[i][j];
        int ans;
        if(word1[i]==word2[j]){
            ans = dp(word1,word2,i-1,j-1);
        }
        else{
            int l1 = dp(word1,word2,i,j-1);
            int l2 = dp(word1,word2,i-1,j);
            int l3 = dp(word1,word2,i-1,j-1);
            ans = min(l1, min(l2, l3))+1;
        }
        memo[i][j] = ans;
        return ans;
    }
};
// @lc code=end

