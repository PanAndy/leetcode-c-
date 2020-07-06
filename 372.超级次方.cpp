/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */

// @lc code=start

#include<iostream>
#include<vector>

using namespace std;

// 这算是我AC的第一道结果取模的题
class Solution {
public:

    int base = 1337;
    int mypow(int a,int b)
    {
        if(b==0)return 1;
        a %= base;
        if(b%2 == 1){
            return (a * mypow(a, b-1)) % base;
        }else{
            int sub = mypow(a, b/2);
            return  (sub * sub) % base;
        }
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty())return 1;
        int last = b.back();
        b.pop_back();
        int part1 = mypow(a, last);
        int part2 = mypow(superPow(a, b), 10);
        return (part1 * part2)%base;
    }
};
// @lc code=end

