/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxF(nums), minF(nums);
        for(int i=1;i<nums.size();i++)
        {
            // 如果不是连续的，就会被更新为nums[i]
            maxF[i] = max(maxF[i-1]*nums[i], max(nums[i], minF[i-1]*nums[i]));
            minF[i] = min(maxF[i-1]*nums[i], min(nums[i], minF[i-1]*nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};
// @lc code=end

