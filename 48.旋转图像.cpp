/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m==0)return;
        int n = matrix[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<m;j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m/2;j++)
            {
                swap(matrix[i][j], matrix[i][m-1-j]);
            }
        }
    }
};
// @lc code=end

