/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int i=0;i<n;++i){
            s+=nums[i];
        }
        if(s%2==1)return false;
        int target = s / 2;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        for(int i = 1;i<n;i++)
        {
            // 从后往前遍历源于在二维数组的形式下，dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i]];
            // 从前往后遍历时，会破坏dp[i-1][j]
            for(int j=target;j>=nums[i];j--)
            {
                if(dp[target])return true;
                dp[j] = dp[j] || dp[j - nums[i]];
            }

        }
        return dp[target];
    }
    // bool canPartition(vector<int>& nums) {
    //     int n = nums.size();
    //     int s = 0;
    //     for(int i=0;i<n;++i){
    //         s+=nums[i];
    //     }
    //     if(s%2==1)return false;
    //     int target = s / 2;
    //     vector<vector<bool> > dp(n, vector<bool>(target+1, 0));
    //     if(nums[0]<= target){
    //         dp[0][nums[0]] = true;
    //     }
    //     for(int i = 1;i<n;i++)
    //     {
    //         for(int j=0;j<=target;j++)
    //         {
    //             if(nums[i]==j)
    //             {
    //                 dp[i][j] = true;
    //                 continue;
    //             }
    //             if(nums[i]<j)
    //             {
    //                 dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i]];
    //             }
    //         }

    //     }
    //     return dp[n-1][target];
    // }
};
// @lc code=end

