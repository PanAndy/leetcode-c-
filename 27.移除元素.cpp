/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int left=0;
        int right=nums.size()-1;

        while(left<=right)
        {
            if(nums[left]==val){
                if(nums[right]!=val){
                    swap(nums[left],nums[right--]);
                }else{
                    right--;
                    continue;
                }
            }
            left++;
        }
        return right+1;

    }
};
// @lc code=end

