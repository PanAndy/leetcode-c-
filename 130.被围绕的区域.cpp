/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class UF{
public:
    int count;
    vector<int> parent;
    vector<int> size;

    UF(int n){
        count = n;
        parent = vector<int>(n+1, 0);
        size = vector<int>(n+1, 0);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    void Union(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ){
            return;
        }
        if(size[rootP] > size[rootQ]){
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }else{
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }

    bool connected(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int find(int x){
        while(parent[x]!=x){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m==0)return;
        int n = board[0].size();

        UF uf(m*n + 1);
        int dummy = m*n;

        for(int i=0;i<m;i++){
            if(board[i][0] == 'O'){
                uf.Union(i * n, dummy);
            }
            if(board[i][n-1]=='O'){
                uf.Union(i * n + n - 1, dummy);
            }
        }

        for(int j = 0;j<n;j++)
        {
            if(board[0][j] == 'O'){
                uf.Union(j, dummy);
            }
            if(board[m-1][j] == 'O'){
                uf.Union(n * (m - 1) + j, dummy);
            }
        }

        vector<vector<int> > dir = {
            {1, 0}, {0, 1}, {0, -1}, {-1, 0}
        };

        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(board[i][j]=='O')
                {
                    for(int k = 0; k<4;k++){
                        int x = i + dir[k][0];
                        int y = j + dir[k][1];
                        if(board[x][y] == 'O'){
                            uf.Union(x * n + y, i * n + j);
                        }
                    }
                }
            }
        }

        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(!uf.connected(i * n + j, dummy))
                {
                    board[i][j] = 'X';
                }
            }
        }

    }
};
// @lc code=end

