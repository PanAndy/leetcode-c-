/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int dup = -1;
        for(int i=0;i<nums.size();i++)
        {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] < 0){
                dup = abs(nums[i]);
            }else{
                nums[idx] *= -1;
            }
        }
        int miss = -1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                miss = i + 1;
            }
        }
        
        return {dup, miss};
    }
};
// @lc code=end

