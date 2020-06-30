/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:

    long long f(long long x, long long t){
        long long ans = x*x - t;
        return ans;
    }
    int mySqrt(int x) {
        if(x==0 || x==1)return x;
        int l=1,r=x/2;
        int m=0;
        while(l<=r){
            m = (l+r)/2;
            if(f(m,x)<0){
                l = m + 1;
            }
            else if(f(m,x)>0){
                r = m - 1;
            }else{
                return m;
            }
        }
        return r;
        // return int(sqrt(x));
    }
};
// @lc code=end

