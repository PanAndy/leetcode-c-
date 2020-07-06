/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0)return 0;
        int slow= 0;
        int fast = 1;
        int cnt = 1;
        while (fast < n)
        {
            if(nums[slow]!=nums[fast]){
                slow++;
                nums[slow] = nums[fast];
                fast++;
                cnt = 1;
            }else{
                cnt++;
                if(cnt<=2){
                    slow++;
                    nums[slow] = nums[fast];
                    fast++;
                }else{
                    fast++;
                }
            }
        }
        return slow+1;
    }
};
// @lc code=end

