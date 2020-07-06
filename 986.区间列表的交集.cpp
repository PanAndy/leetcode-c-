/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int a = 0, b = 0;
        vector<vector<int> > res;

        while (a < A.size()  && b < B.size())
        {
            int a1 = A[a][0], a2 = A[a][1];
            int b1 = B[b][0], b2 = B[b][1];

            if(b2 >= a1 && a2 >= b1){
                res.push_back({max(a1, b1), min(a2, b2)});
            }

            if(b2 < a2){
                ++b;
            }else{
                ++a;
            }
        }
        return res;
    }
};
// @lc code=end

