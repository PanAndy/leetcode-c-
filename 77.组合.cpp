/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:


    vector<vector<int> > res;

    vector<vector<int>> combine(int n, int k) {
        res.clear();
        if(k<=0 || n<=0)return res;
        vector<int> track;
        backtrack(n, k, 1, track);
        return res;    
    }

    void backtrack(int n, int k, int start, vector<int> track)
    {
        if(k == track.size()){
            res.push_back(track);
            return;
        }

        // 之所以有这个start，是因为在组合中，1 2 和 2 1是一个组合
        for(int i=start;i<=n;i++){
            track.push_back(i);
            backtrack(n, k, i+1, track);
            track.pop_back();
        }
    }

};
// @lc code=end

