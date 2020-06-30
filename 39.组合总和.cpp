/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    vector<vector<int> > ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        vector<int> path;
        backtracking(candidates, path, target, 0, 0);
        return ans;
    }

    void backtracking(vector<int> &candidates, vector<int> &path, int target, int s, int b)
    {
        if(s==target){
            ans.push_back(path);
            return;
        }else if(s>target){
            return;
        }
        for(int i=b;i<candidates.size();i++)
        {
            path.push_back(candidates[i]);
            backtracking(candidates, path, target, s+candidates[i], i);
            path.pop_back();
        }
    }
};
// @lc code=end

