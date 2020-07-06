/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<stack>

using namespace std;
class Solution {
public:

    bool cycle = false;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        if(numCourses==0)return {};
        vector<int> ans;
        if(m==0){
            for(int i=0;i<numCourses;i++){
                ans.push_back(i);
            }
            return ans;
        }
        cycle = false;
        vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0));
        vector<int> visited(numCourses, 0);
        vector<int> stacked(numCourses, 0);
        stack<int> reversePost;

        for(auto edge : prerequisites){
            graph[edge[1]][edge[0]] = 1;
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i])
                dfs(graph, visited, stacked, reversePost, i, numCourses);
        }
        if(cycle){
            return {};
        }


        while(!reversePost.empty())
        {
            ans.push_back(reversePost.top());
            reversePost.pop();
        }
        return ans;
    }

    void dfs(vector<vector<int> > &graph, vector<int> &visited, vector<int> &stacked, stack<int> &reversePost, int v, int m)
    {
        visited[v] = 1;
        stacked[v] = 1;
        if(cycle)return ;
        for(int i=0;i<m;i++)
        {
            if(graph[v][i]){
                if(visited[i]==0)
                {
                    dfs(graph, visited, stacked, reversePost, i, m);
                }
                else if(stacked[i])
                {
                    cycle = true;
                    return;
                }
            }
        }
        reversePost.push(v);
        stacked[v] = 0;
    }

};
// @lc code=end

