/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    void solveSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if(m!=n || m!=9 || n!=9) return;
        backtrack(board, 0, 0);
    }

    bool backtrack(vector<vector<char>>& board, int i, int j)
    {
        int m = 9, n = 9;
        if(j==n){
            return backtrack(board, i+1, 0);
        }
        if(i==m){
            return true;
        }
        if(board[i][j]!='.'){
            return backtrack(board, i, j+1);
        }

        for(char ch = '1'; ch <= '9'; ch++){
            if(!isValid(board, i, j, ch))
            {
                continue;
            }
            board[i][j] = ch;
            if(backtrack(board, i, j+1)){
                return true;
            }
            board[i][j] = '.';
        }
        return false;
    }
    bool isValid(vector<vector<char>> &board, int r, int c, char n)
    {
        for(int i=0;i<9;i++){
            if(board[r][i]==n) return false;
            if(board[i][c]==n) return false;
            // 我去，这种表示真是太巧妙了
            if(board[(r/3)*3+i/3][(c/3)*3 + i%3]==n)return false;
        }
        return true;
    }
};
// @lc code=end

