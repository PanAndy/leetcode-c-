/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])-1]>0)
                nums[abs(nums[i])-1] = - nums[abs(nums[i])-1];
            else{
                ans.push_back(abs(nums[i]));
            }
        }
        return ans;
    }

};
// @lc code=end

