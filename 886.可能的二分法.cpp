/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) 
    {
        vector<int> father((N+1)*2+10, 0);
        for(int i=1;i<(N+1)*2;i++) father[i] = i;
        for(int i=0;i<dislikes.size();i++)
        {
            int x = find(dislikes[i][0], father);
            int y = find(dislikes[i][1], father);
            int a = find(dislikes[i][0] + N, father);
            int b = find(dislikes[i][1] + N, father);
            if(x == y) return false;
            else{
                father[a] = y;
                father[b] = x;
            }
            
        }
        return true;
    }

    int find(int x, vector<int>& father)
    {
        while(x!=father[x])
        {
            x = father[x];
            father[x] = father[father[x]];
        }
        return father[x];
    }

};
// @lc code=end

