/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start

#include<iostream>
using  namespace std;

class Solution {
public:
    int fib(int N) {
        if(N==0)return 0;
        if(N==1)return 1;
        int f = 0;
        int g = 1;
        for(int i=2;i<=N;++i)
        {
            int h = f + g;
            f = g;
            g = h;
        }
        return g;
    }
};
// @lc code=end

