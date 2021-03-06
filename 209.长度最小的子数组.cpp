/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        int ans = INT_MAX;
        vector<int> sums(n+1, 0);
        for(int i=1;i<=n;i++){
            sums[i] = sums[i-1] + nums[i-1];
        }
        for(int i=1;i<n;i++)
        {
            int target = s + sums[i-1];
            auto bound = lower_bound(sums.begin(), sums.end(), target);
            if(bound!=sums.end())
            {
                ans = min(ans, static_cast<int>((bound - sums.begin()) - (i-1)));
            }
        }
        return ans == INT_MAX ? 0 : ans;

    }
    // int minSubArrayLen(int s, vector<int>& nums) {
    //     int n = nums.size();
    //     if(n==0)return 0;
    //     int l=0, r=0;

    //     int m = INT_MAX;
    //     int Sum = nums[0];
    //     while(r < n)
    //     {
    //         if(Sum < s)
    //         {
    //             if(r+1<n)
    //             {
    //                 Sum += nums[++r];
    //             }else{
    //                 break;
    //             }
    //         }else{
    //             m = min(m, r - l + 1);
    //             Sum -= nums[l++];
    //         }
    //     }
    //     return m==INT_MAX ? 0 : m;
    // }
};
// @lc code=end

