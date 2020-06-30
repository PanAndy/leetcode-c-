/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int M = needle.size();
        int N = haystack.size();
        if(N==0 && M==0)return 0;
        if(N==0 && M!=0)return -1;
        if(N!=0 && M==0)return 0;
        vector<vector<int> > dp(M, vector<int>(256, 0));
        dp[0][needle[0]] = 1;
        int X = 0;
        for(int j = 1; j < M; ++j)
        {
            for(int c = 0; c < 256; ++c)
            {
                dp[j][c] = dp[X][c];
            }
            dp[j][needle[j]] = j + 1;
            X = dp[X][needle[j]];
            //这始终记录的是与j具有最长的相同前缀
        }

        int j = 0;
        for(int i=0;i<N;++i)
        {
            j = dp[j][haystack[i]];
            if(j == M) return i - M + 1;
        }
        return -1;
    }
    // int strStr(string haystack, string needle) {
    //     if(needle=="")return 0;
    //     if(haystack.length()<needle.length())return -1;
    //     for(int i=0;i<haystack.length()-needle.length()+1;++i){
    //         if(haystack.substr(i,needle.length())==needle){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
};
// @lc code=end

