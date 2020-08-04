// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem300.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int n = nums.size();
        vector<int> piles(n+1, 1);
        int idx = 1;
        piles[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            int left = 0;
            int right = idx;
            while(left<right)
            {
                int mid = left + (right - left) / 2;

                if(nums[i] <= piles[mid]){
                    right = mid;
                }
                else{
                    left = mid + 1;
                }
            }
            if(left == idx)
            {
                idx++;
            }
            piles[left] = nums[i];
        }
        
        return idx;
    }
    // int lengthOfLIS(vector<int>& nums) {
    //     if(nums.size()==0)return 0;
    //     vector<int> dp(nums.size(), 1);

    //     for(int i=0;i<nums.size();i++)
    //     {
    //         for(int j=0;j<i;j++)
    //         {
    //             if(nums[i] > nums[j])
    //                 dp[i] = max(dp[i], dp[j] + 1);
    //         }
    //     }
    //     int ans = 0;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         ans = max(ans, dp[i]);
    //     }
    //     return ans;
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     if(nums.size()==0)return 0;
    //     vector<int> dp(nums.size(), 0);
    //     dp[0] = 1;
    //     for(int i = 1; i < nums.size(); ++i)
    //     {
    //         for(int j = 0; j < i; ++j)
    //         {
    //             if(nums[j] < nums[i])
    //             {
    //                 dp[i] = max(dp[i], dp[j]);
    //             }
    //         }
    //         dp[i] += 1;
    //     }
    //     int ans = 0;
    //     for(int i = 0; i < dp.size(); ++i)
    //     {
    //         ans = max(ans, dp[i]);
    //     }
    //     return ans;
    // }
};
// @lc code=end

