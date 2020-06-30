/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0, n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(i<=maxPos)
            {
                maxPos = max(maxPos, i + nums[i]);
                if(maxPos>=n-1)return true;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

