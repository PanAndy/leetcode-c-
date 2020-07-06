/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        for(int i=1;i<=num;++i)
        {
            ans[i] = ans[i & (i-1)] + 1;
        }
        return ans;
    }
    // vector<int> countBits(int num) {
    //     vector<int> ans(num+1, 0);
    //     for(int i=0;i<=num;++i)
    //     {
    //         ans[i] = popcount(i);
    //     }
    //     return ans;
    // }

    // int popcount(int x)
    // {
    //     int cnt = 0;
    //     while(x)
    //     {
    //         x &= (x-1);
    //         cnt++;
    //     }
    //     return cnt;
    // }
};
// @lc code=end

