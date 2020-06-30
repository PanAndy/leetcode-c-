/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        
    }

    bool match(string &s, string &p, int i, int j)
    {
        if(i==s.size() && j>=p.size())return true;

        if(i==s.size() || j==p.size()) return false;

        if(p[j] == '*')
        {
            if()
        }else if(p[j] == '?'){
            return match(s, p, i+1, j+1);
        }else if(s[i]==p[j]){
            return match(s, p, i+1, j+1);
        }
        return false;
    }

};
// @lc code=end

