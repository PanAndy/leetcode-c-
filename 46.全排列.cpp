/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        path.clear();
        dfs(nums, 0);;
        return ans;
    }

    void dfs(vector<int>& nums, int pos)
    {
        if(pos == nums.size()){
            ans.push_back(path);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            // 在排列中 1 2 3 和 1 3 2 不是一个排列，所以不必要像组合问题里从k开始
            if(find(path.begin(),path.end(), nums[i])!=path.end())
            {
                continue;
            }
            path.push_back(nums[i]);
            dfs(nums, pos+1);
            path.pop_back();
        }
    }
};
// @lc code=end

