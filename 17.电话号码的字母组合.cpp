/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    map<char, string> m;

    void init()
    {
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
    }
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        ans.clear();
        init();
        if(digits.size()==0)return ans;
        string path;
        backtrack(digits, 0, path);

        return ans;
    }

    void backtrack(string &digits, int pos, string path)
    {
        if(pos == digits.size())
        {
            ans.push_back(path);
        }

        for(auto ch : m[digits[pos]])
        {
            path.push_back(ch);
            backtrack(digits, pos+1, path);
            path.pop_back();
        }
    }
};
// @lc code=end

