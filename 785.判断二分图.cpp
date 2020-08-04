/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    vector<bool> marked;
    vector<bool> color;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        marked = vector<bool>(n, false);
        color = vector<bool>(n, false);
        for(int i=0;i<n;i++)
        {
            if(!marked[i])
            {
                if(!dfs(graph, i)){
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>> &graph, int v)
    {
        marked[v] = true;
        for(int i=0;i<graph[v].size();i++)
        {
            if(!marked[graph[v][i]]){
                color[graph[v][i]] = !color[v];
                if(!dfs(graph, graph[v][i]))return false;
            }else if(color[graph[v][i]] == color[v]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

