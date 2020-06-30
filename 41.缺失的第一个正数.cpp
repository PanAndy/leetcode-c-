/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        int flag = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                flag = 1;
            }
        }
        
        if(flag==0)return 1;
        if(n==1)return 2;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=0 || nums[i]>n)
                nums[i]=1;
        }
        for(int i=0;i<n;i++)
        {   
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);           
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                return i+1;
            }
        }
        return n+1;
    }
};
// @lc code=end

