/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0)return -1;
        int l = 0, r = n - 1;

        while(l<=r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                l = mid + 1;
            }else if(nums[mid] > target){
                r = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

