// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem368.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return {};

        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> path(n, -1);
        int max_len = 0;
        int man_idx = -1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] % nums[j] == 0)
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        path[i] = j;
                    }
                }
            }
            if(dp[i] > max_len)
            {
                max_len = dp[i];
                man_idx = i;
            }
        }

        vector<int> ans;

        for(int ind = man_idx;ind!=-1;ind = path[ind])
        {
            ans.push_back(nums[ind]);
        }
        return ans;

    }
    // vector<int> largestDivisibleSubset(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n==0)return {};

    //     vector<vector<int>> EDS;
    //     for(auto i : nums){
    //         EDS.push_back({});
    //     }
    //     sort(nums.begin(), nums.end());

    //     for(int i=0;i<n;i++){
    //         vector<int> maxSubset = {};
    //         for(int k=0;k<i;k++)
    //         {
    //             if(nums[i] & nums[k]==0 && maxSubset.size() < EDS[k].size())
    //             {
    //                 maxSubset=(EDS[k]);
    //             }
    //         }
    //         EDS[i] = maxSubset;
    //         EDS[i].push_back(nums[i]);
    //     }
    //     vector<int> ret;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(ret.size() < EDS[i].size()){
    //             ret = EDS[i];
    //         }
    //     }
    //     return ret;
    // }
};
// @lc code=end

