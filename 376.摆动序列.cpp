/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        int n = nums.size();
        vector<int> up(n, 0);
        vector<int> down(n, 0);
        up[0] = 1;
        down[0] = 1;
        for(int i=1;i<n;i++)
        {
            if(nums[i] > nums[i-1])
            {
                up[i] = down[i-1] + 1;
                down[i] =down[i-1];
            }else if(nums[i] < nums[i-1])
            {
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];
            }else{
                down[i] = down[i-1];
                up[i] = up[i-1];
            }
        }
        return max(up[n-1], down[n-1]);
    }
    // int wiggleMaxLength(vector<int>& nums) {
    //     if(nums.size()<2)return nums.size();
    //     int n = nums.size();
    //     vector<int> up(n, 0);
    //     vector<int> down(n, 0);
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<i;j++)
    //         {
    //             if(nums[i]>nums[j])
    //             {
    //                 up[i] = max(up[i], down[j]+1);
    //             }else if(nums[i]<nums[j])
    //             {
    //                 down[i] = max(down[j], up[j]+1);
    //             }
    //         }
    //     }
    //     return 1 + max(down[n-1], up[n-1]);
    // }
};
// @lc code=end

