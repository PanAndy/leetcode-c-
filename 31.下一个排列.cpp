/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = nums.size()-1;
        while(pos>0&&nums[pos]<=nums[pos-1]){
            pos--;
        }
        reverse(nums.begin()+pos,nums.end());
        if(pos>0){
            for(int i=pos;i<nums.size();i++){
                if(nums[i]>nums[pos-1]){
                    swap(nums[i],nums[pos-1]);
                    break;
                }
            }
        }
        
    }
};
// @lc code=end

