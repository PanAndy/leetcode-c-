/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:

    string palindrome(string& s, int l, int r){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<2)return s;
        string res;
        for(int i=0;i<s.size();i++){
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i+1);
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }
        return res;
    }
    // string longestPalindrome(string s) {
    //     int n = s.size();
    //     if(n<2)return s;
    //     vector<vector<int> > dp(n, vector<int>(n, 0));
    //     int maxLen = 1;
    //     int begin = 0;
    //     for(int j=1;j<n;++j)
    //     {
    //         for(int i=0;i<j;i++)
    //         {
    //             if(s[i]!=s[j])
    //             {
    //                 dp[i][j] = 0;
    //             }else{
    //                 if(j-i<3){
    //                     dp[i][j] = 1;
    //                 }else{
    //                     dp[i][j] = dp[i+1][j-1];
    //                 }
    //             }
    //             if(dp[i][j]&&j-i+1>maxLen)
    //             {
    //                 maxLen = j-i+1;
    //                 begin = i;
    //             }
    //         }
    //     }
    //     return s.substr(begin, maxLen);
    // }
};
// @lc code=end

