/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

// @lc code=start

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = 2;
        int n = 3;
        string target = "123450";

        string start = "";
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                start.push_back(board[i][j]+'0');
            }
        }
        //这种表示neighbor还不用担心越界问题
        vector<vector<int> > neighbor={
            {1, 3},
            {0,4,2},
            {1,5},
            {0,4},
            {3,1,5},
            {4,2}
        };

        queue<string> q;
        set<string> visited;
        q.push(start);
        visited.insert(start);
        int step = 0;
        while (!q.empty())
        {
            int sz = q.size();

            for(int i=0;i<sz;i++){
                string cur=q.front();
                q.pop();
                if(target == cur){
                    return step;
                }
                int idx = 0;
                for(;cur[idx]!='0';++idx);

                for(int adj : neighbor[idx]){
                    string new_board = cur;
                    swap(new_board[adj], new_board[idx]);
                    if(!visited.count(new_board))
                    {
                        q.push(new_board);
                        visited.insert(new_board);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end

