/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0], mn = nums[0];
        int ans = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            int mxF = mx, mnF = mn;
            mx = max(nums[i], max(nums[i]*mxF, nums[i]*mnF));
            mn = min(nums[i], min(nums[i]*mxF, nums[i]*mnF));
            ans = max(ans, mx);
        }
        return ans;
    }
};
// @lc code=end

