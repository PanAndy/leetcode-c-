/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), cmp);

        int n = intervals.size();
        if(n==0)return 0;

        int m = 1;
        int x_end = intervals[0][1];
        for(int i=0;i<n;++i)
        {
            int start = intervals[i][0];
            if(start >= x_end)
            {
                m++;
                x_end = intervals[i][1];
            }
        }
        return n - m;
    }

    static bool cmp(const vector<int> &a, const vector<int> &b){
        return a[1] < b[1];
    }
};
// @lc code=end

