/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()<=1)return nums.size();
        int pos = 1;
        int pre = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==pre){
                continue;
            }else{
                nums[pos++]=nums[i];
                pre = nums[i];
            }
        }
        return pos;
    }
};
// @lc code=end

