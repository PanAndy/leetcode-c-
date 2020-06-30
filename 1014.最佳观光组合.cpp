/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<iostream>
#include<climits>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = 0;
        int mx = A[0] + 0;

        for(int j=1;j<A.size();++j)
        {
            ans = max(ans, mx + A[j] - j);
            mx = max(mx, A[j]+j);
        }
        return ans;
    }
};
// @lc code=end

