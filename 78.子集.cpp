/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        vector<int> track;
        backtrack(nums, 0, track);
        return res;
    }
    void backtrack(vector<int>& nums, int start, vector<int>& track){
        res.push_back(track);
        for(int i=start;i<nums.size();i++)
        {
            track.push_back(nums[i]);
            backtrack(nums, i+1, track);
            track.pop_back();
        }
    }

    // vector<vector<int>> subsets(vector<int>& nums) {
    //     if(nums.empty())return {{}}; 
    //     int n = nums.back();
    //     nums.pop_back();
    //     vector<vector<int> > res = subsets(nums);

    //     int size = res.size();
    //     for(int i=0;i<size;i++){
    //         res.push_back(res[i]);
    //         res.back().push_back(n);
    //     }
    //     return res;
    // }
};
// @lc code=end

