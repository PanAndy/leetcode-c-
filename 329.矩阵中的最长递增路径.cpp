/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

class Solution {
public:


    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0)return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> grid(m+2, vector<int>(n+2, 0));
        vector<vector<int>> outdegree(m+2, vector<int>(n+2, 0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                grid[i+1][j+1] = matrix[i][j];
            }
        }

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(auto d : dir){
                    if(grid[i][j] < grid[i+d[0]][j+d[1]]){
                        outdegree[i][j]++;
                    }
                }
            }
        }

        n+=2;
        m+=2;
        vector<vector<int>> leaves;
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++){
                if(outdegree[i][j]==0){
                    leaves.push_back({i,j});
                }
            }
        }

        int height = 0;
        while (!leaves.empty())
        {
            height++;
            vector<vector<int>> newLeaves;
            for(auto node : leaves)
            {
                for(auto d : dir)
                {
                    int x = node[0] + d[0];
                    int y = node[1] + d[1];
                    if(grid[node[0]][node[1]]>grid[x][y]){
                        if(--outdegree[x][y]==0){
                            newLeaves.push_back({x,y});
                        }
                    }
                }
            }
            leaves = newLeaves;
        }
        return height;

    }


    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    // int m, n;
    // int longestIncreasingPath(vector<vector<int>>& matrix) {
    //     if(matrix.size()==0)return 0;
    //     m = matrix.size();
    //     n = matrix[0].size();
    //     vector<vector<int>> memo(m, vector<int>(n, 0));
    //     int ans = 0;
    //     for(int i=0;i<m;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //         {
    //             ans = max(ans, dfs(matrix, i, j, memo));
    //         }
    //     }
    //     return ans;
    // }

    // int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &memo)
    // {
    //     if(memo[i][j]!=0)return memo[i][j];

    //     for(auto d : dir){
    //         int x = i + d[0];
    //         int y = j + d[1];
    //         if(x>=0 && x<m && y>=0 && y<n && matrix[x][y] > matrix[i][j])
    //         {
    //             memo[i][j] = max(memo[i][j], dfs(matrix, x, y, memo));
    //         }
    //     }
    //     return ++memo[i][j];
    // }
};
// @lc code=end

