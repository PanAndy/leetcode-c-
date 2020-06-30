/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    vector<vector<int> > ans;
    set<vector<int> > mp;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        mp.clear();

        vector<int> path;
        sort(candidates.begin(),candidates.end());
        
        backtracking(candidates, path, target, 0, 0);
        return ans;
    }

    bool backtracking(vector<int> &candidates, vector<int> &path, int target, int s, int b)
    {
        if(s==target){
            ans.push_back(path);
            // if(mp.count(path)==0)
            // {
            //     ans.push_back(path);
            //     mp.insert(path);
            // }   
            return true;
        }else if(s>target){
            return false;
        }
        for(int i=b;i<candidates.size();i++)
        {
            if(i>b && candidates[i]==candidates[i-1])
                continue;
            path.push_back(candidates[i]);
            bool flag = backtracking(candidates, path, target, s+candidates[i], i + 1);
            path.pop_back();
        }
        return false;
    }
};
// @lc code=end

