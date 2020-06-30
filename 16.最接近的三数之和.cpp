/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        
        sort(nums.begin(),nums.end());
        int s = nums[nums.size()-1] + nums[nums.size()-2] + nums[nums.size()-3];

        for(int i=0;i<nums.size()-2;i++)
        {
            int left = i + 1;
            int right = nums.size()-1;
            int last = 0;
            while (left<right)
            {
                int s_3 = nums[i] + nums[left] + nums[right];
                if(abs(s_3-target)<abs(s-target)){
                    s = s_3;
                }
                if(s_3-target<0){
                    left++;
                }else if(s_3-target>0){
                    right--;
                }else{
                    return s;
                }
            }
        }
        return s;

    }
};
// @lc code=end

