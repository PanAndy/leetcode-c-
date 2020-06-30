/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include<iostream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0, right = 0;
        map<char, int> window;
        int res = 0;
        while (right < s.size())
        {
            char c1 = s[right];
            window[c1]++;
            right++;
            while(window[c1] > 1){
                char c2 = s[left];
                window[c2]--;
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};
// @lc code=end

