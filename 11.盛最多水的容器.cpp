/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int max_area = 0;
        while(left<right){
            max_area = max(max_area,(right-left)*min(height[right],height[left]));
            if(height[left]<height[right]){
                ++left;
            }else{
                --right;
            }
        }
        return max_area;
    }
};
// @lc code=end

