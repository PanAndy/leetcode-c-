/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrim(n, true);
        for(int i=2;i*i<n;++i)
        {
            if(isPrim[i])
            {
                //因为比i小的倍数已经被标记过了
                for(int j=i*i;j<n;j+=i)
                {
                    isPrim[j]=false;
                }
            }
        }
        int cnt = 0;
        for(int i=2;i<n;++i)
        {
            if(isPrim[i])cnt++;
        }
        return cnt;
    }
};
// @lc code=end

