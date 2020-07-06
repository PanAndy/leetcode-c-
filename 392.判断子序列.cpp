/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m ==0 ) return true;
        if(n == 0 )return false;

        int i = 0;
        int j = 0;

        while(i < m && j < n)
        {
            if(s[i] == t[j])
            {
                i++;
            }
            j++;
        }
        return i == m;
    }
};
// @lc code=end

