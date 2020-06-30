/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> Sum(n+1, 0);
        Sum[0] = 0;
        map<int, int> m;
        m[Sum[0]] = 1;
        int ans = 0, sum0_i = 0;
        for(int i=0;i<n;i++)
        {
            sum0_i += nums[i];
            int sum0_j = sum0_i - k;
            if(m.count(sum0_j)){
                ans += m[sum0_j];
            }
            m[sum0_i] = m[sum0_i] + 1; // 等于sum0_i的子数组 的个数，因为可能会有负的，数组和不一定是递增的
        }
        return ans;
    }
};
// @lc code=end

