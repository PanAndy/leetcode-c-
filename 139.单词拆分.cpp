/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start

#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict){
        set<string> wdS;
        for(int i=0;i<wordDict.size();++i){
            wdS.insert(wordDict[i]);
        }
        int len = s.size();
        vector<int> dp(len+1, false);
        dp[0] = true;
        for(int i=1;i<=len;++i){
            for(int j = 0;j < i;++j){
                
                if(dp[j]&&wdS.find(s.substr(j, i-j))!=wdS.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[len];

    }
    // 这为啥不行呢？
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     int len = s.size();
    //     if(len<=0)return true;
    //     vector<int> dp(len+1, false);
    //     dp[0] = true;

    //     for(int i=1;i<=len;++i)
    //     {
    //         for(int j=0;j<wordDict.size();++j)
    //         {
    //             if(i-(int)wordDict[j].size()>=0)
    //             {
    //                 // cout<<i<<endl;
    //                 // cout<<s.substr(i-(int)wordDict[j].size(),(int) wordDict[j].size())<<endl;
    //                 // cout<<(s.substr(i-(int)wordDict[j].size(),(int) wordDict[j].size()) == wordDict[j])<<endl;
    //                 // cout<<dp[i-(int)wordDict[j].size()]<<endl;

    //                 dp[i] = (s.substr(i-(int)wordDict[j].size(),(int) wordDict[j].size()) == wordDict[j]) && dp[i-(int)wordDict[j].size()];
    //                 // cout<<dp[i]<<endl;
    //             }
    //         }
    //     }
    //     return dp[len];
    // }
};
// @lc code=end

