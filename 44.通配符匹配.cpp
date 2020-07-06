/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        memo.clear();
        if(p==s)return true;
        if(p=="")return false;
        string p_tmp;
        p_tmp.push_back(p[0]);
        for(int i=1;i<p.size();i++)
        {
            if(p[i]!='*'){
                p_tmp.push_back(p[i]);
            }else if(p[i]=='*' && p[i-1]!='*'){
                p_tmp.push_back(p[i]);
            }
        }
        // cout<<p_tmp<<endl;
        return match(s, p_tmp, 0, 0);
    }
    map<pair<int,int>, bool> memo;

    bool match(string &s, string &p, int s_pos, int p_pos)
    {
        if(memo.count(make_pair(s_pos,p_pos)))return memo[make_pair(s_pos,p_pos)];
        bool ans = false;
        if(p.substr(p_pos)==s.substr(s_pos) || p.substr(p_pos)=="*") ans = true;
        else if(p.substr(p_pos) == "" || s.substr(s_pos) == "") ans = false;
        else if(p[p_pos]==s[s_pos] || p[p_pos]=='?')
        {
            ans = match(s, p, s_pos, p_pos);
        }
        else if(p[p_pos]=='*'){
            ans = match(s, p, s_pos, p_pos+1) || match(s, p, s_pos+1, p_pos);
        }
        memo[make_pair(s_pos,p_pos)] = ans;
        return ans;
    }
};
// @lc code=end

