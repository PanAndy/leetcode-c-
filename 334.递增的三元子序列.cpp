/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;

        int small = INT_MAX;
        int mid = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=small)
            {
                small = nums[i];
            }else if(nums[i] <= mid)
            {
                mid = nums[i];
            }else if(nums[i] > mid)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

