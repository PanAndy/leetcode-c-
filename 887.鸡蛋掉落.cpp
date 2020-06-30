/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start

#include<iostream>
#include<algorithm>

using namespace std;
class Solution {
public:

    int memo[110][10010];
    int superEggDrop(int K, int N) {
        memset(memo, 0, sizeof(memo));
        return dp(K, N);
    }
    int dp(int K, int N)
    {
        if(K==1)return N;
        if(N==0)return 0;
        if(memo[K][N]!=0) return memo[K][N];

        int res = INT_MAX;
        // for(int i=1;i<=N;i++)
        // {
        //     res = min(res, max(dp(K,N-i), dp(K-1, i-1))+1);
        // }
        // 必须用二分才能过
        int lo = 1;
        int hi = N;
        while(lo<=hi)
        {
            int mid = (lo + hi) / 2;
            int broken = dp(K-1, mid-1);
            int not_broken = dp(K, N-mid);
            if(broken>not_broken)
            {
                hi = mid - 1;
                res = min(res, broken+1);
            }else{
                lo = mid + 1;
                res = min(res, not_broken+1);
            }
        }
        memo[K][N] = res;
        return res;
    }
};
// @lc code=end

