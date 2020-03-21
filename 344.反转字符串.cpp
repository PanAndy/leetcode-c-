/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0,r=s.size()-1;

        while(l<r){
            char tmp=s[l];
            s[l]=s[r];
            s[r]=tmp;
            ++l;
            --r;          
        }
    }
};
// @lc code=end

