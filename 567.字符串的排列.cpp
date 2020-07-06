/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
#include<iostream>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    // 在s2中，是否包含s1中所有字符组成的的子串
    bool checkInclusion(string s1, string s2) {
        map<char, int> needs;
        map<char, int> window;
        for(char ch : s1)
        {
            needs[ch]++;
        }

        int left = 0;
        int right = 0;
        int match = 0;
        while (right < s2.size())
        {
            if(needs.count(s2[right]))
            {
                window[s2[right]]++;
                if(window[s2[right]] == needs[s2[right]]){
                    match++;
                }
            }
            right++;
            while(right - left >= s1.size())
            {
                if(match == needs.size())return true;
                if(needs.count(s2[left]))
                {
                    if(window[s2[left]]==needs[s2[left]])
                        match--;
                    window[s2[left]]--;
                }
                left++;
            }
        }
        return false;

    }
};
// @lc code=end

