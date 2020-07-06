/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int lenA = A.size();
        int lenB = B.size();
        if(lenA==0 || lenB==0)return 0;
        vector<vector<int> > grid(lenA, vector<int>(lenB, 0));

        for(int i=0;i<lenA;i++)
        {
            for(int j=0;j<lenB;j++)
            {
                if(A[i] == B[j]){
                    grid[i][j] = 1;
                }
            }
        }
        int res = 0;
        for(int i = 0;i<lenA;i++)
        {
            for(int j = 0; j<lenB ;j++){
                int common = 0;
                if(grid[i][j] == 1){
                    for(int r = i, s = j;r<lenA && s<lenB;r++, s++){
                        if(grid[r][s] == 1)
                        {
                            common++;
                            grid[r][s] = 0;
                        }else{
                            break;
                        }
                    }
                }
                res = max(res, common);
            }
        }
        return res;
    }
};
// @lc code=end

