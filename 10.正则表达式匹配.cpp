/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // return doMatch(s, p, 0, 0);
        memset(memo, 0, sizeof(memo));
        return state(s, p, 0, 0);
    }

    // bool doMatch(string &s, string &p, int s_pos, int p_pos)
    // {
    //     if(p_pos>=p.size())return s_pos>=s.size();
    //     bool currentMatch = s_pos<s.size() && (s[s_pos]==p[p_pos] || p[p_pos]=='.');
    //     if(p_pos<p.size()-1 && p[p_pos+1]=='*')
    //     {
    //         return doMatch(s,p,s_pos,p_pos+2)||(doMatch(s,p,s_pos+1,p_pos)&&currentMatch);
    //     }
    //     else{
    //         return currentMatch && doMatch(s, p, s_pos+1, p_pos+1);
    //     }
    // }

    int memo[1000][1000];
    bool state(string &s, string &p, int s_pos, int p_pos)
    {

        bool ans = false;
        if(s_pos==s.size() && p_pos>=p.size()) return true;
     
        if(s_pos!=s.size() && p_pos==p.size())return false;

        if(memo[s_pos][p_pos]!=0)return memo[s_pos][p_pos] == 2;
        if(p_pos<p.size()-1 && p[p_pos+1] == '*'){
            if(s[s_pos] == p[p_pos] || (p[p_pos]=='.' && s_pos!=s.size())){
                ans = state(s, p, s_pos+1, p_pos) || state(s, p, s_pos, p_pos+2);
            }else
            {
                ans = state(s, p, s_pos, p_pos+2);
            }
        }
        else if((p[p_pos]=='.' && s_pos<s.size()) || s[s_pos]==p[p_pos])
            ans = state(s, p, s_pos+1, p_pos+1);
        
        memo[s_pos][p_pos] = int(ans) + 1;
        return ans;
    }

};
// @lc code=end

