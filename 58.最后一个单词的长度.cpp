/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start

#include<iostream>
#include<string>
#include<sstream>

using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        string last;
        stringstream ss(s);
        while(ss>>last);
        return last.length();
    }
};
// @lc code=end

