/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int i : nums)sum+=i;
        if(sum % k > 0) return false;
        int target = sum / k;

    }
    bool canPartitionKSubsets2(vector<int>& nums, int k) {
        int sum = 0;
        for(int i : nums)sum+=i;
        if(sum % k > 0) return false;
        int target = sum / k;

        sort(nums.begin(), nums.end());
        int row = nums.size() - 1;
        if(nums[row] > target) return false;
        while(row>=0 && nums[row] == target){
            row--;
            k--;
        }
        return search(vector<int>(k, 0), row, nums, target);
    }
    bool search(vector<int> groups, int row, vector<int> nums, int target)
    {
        if(row < 0) return true;
        int v = nums[row--];
        for(int i=0;i<groups.size();i++)
        {
            if(groups[i]+v <= target)
            {
                groups[i] += v;
                if(search(groups, row, nums, target))return true;
                groups[i] -= v;
            }
        }
        return false;
    }
};
// @lc code=end

