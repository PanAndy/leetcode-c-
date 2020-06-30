/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || x!=0 && x%10==0)return false;
        int t = x;
        int s=0;
        while(s<x){
            s = s * 10 + x % 10;
            x/=10;
        }
        return x==s||(x==s/10);
    }
};
// @lc code=end

