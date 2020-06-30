/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int m = points.size();
        if(m==0)return 0;
        sort(points.begin(), points.end(), cmp);
        int x_end = points[0][1];
        int c = 1;
        for(int i=0;i<m;i++)
        {
            if(points[i][0] > x_end)
            {
                c++;
                x_end = points[i][1];
            }
        }
        return c;
    }
    static bool cmp(const vector<int> &a, const vector<int> b)
    {
        return a[1] < b[1];
    }
};
// @lc code=end

