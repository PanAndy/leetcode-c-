/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int m = intervals.size();
        if(m==0)return {};

        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;

        res.push_back(intervals[0]);
        for(int i=1;i<m;++i){
            vector<int> curr = intervals[i];
            vector<int> &last = res.back(); //这种引用的机制真是强大
            //还有这种解决思维
            if(curr[0] <= last[1])
            {
                last[1] = max(last[1], curr[1]);
            }else{
                res.push_back(curr);
            }
        }
        return res;
    }
};
// @lc code=end

