/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start

#include<iostream>
#include<vector>

using namespace std;
class NumArray {
public:
    vector<int> preSum;
    NumArray(vector<int>& nums) {
        preSum = vector<int>(nums.size() + 1, 0);
        for(int i=0;i<nums.size();i++)
        {
            preSum[i+1] = preSum[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return preSum[j+1] - preSum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

