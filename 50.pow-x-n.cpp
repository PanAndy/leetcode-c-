/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include<iostream>

using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        
        long long N = n;
        // - max 会超过int的最大表示形式
        // 第一次实际情况中遇到这个问题
        return N>=0 ? quickPow(x, N) : 1/quickPow(x, -N);
    }

    double quickPow(double x, long long n)
    {
        if(n==0)return 1.0;
        
        if(n%2 == 1){
            return x * quickPow(x, n-1);
        }else{
            double sub = quickPow(x, n/2);
            return sub * sub;
        }
    }
};
// @lc code=end

