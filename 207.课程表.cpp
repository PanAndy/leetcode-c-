/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // dfs 判断里面有没有环即可

        int m = prerequisites.size();
        if(m==0)return true;

        vector<vector<int> > graph(numCourses, vector<int>(numCourses, 0));
        vector<int > marks(numCourses, 0);
        vector<int > stacked(numCourses, 0);

        for(auto edge : prerequisites)
        {
            graph[edge[1]][edge[0]] = 1;
        }

        for(int i=0;i<numCourses;i++)
        {
            if(dfs(graph, marks, stacked, i, numCourses)==false){
                return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int> > &graph, vector<int> &marks, vector<int> &stacked, int v, int m)
    {
        marks[v] = 1;
        stacked[v] = 1;
        for(int i=0;i<m;i++)
        {
            if(graph[v][i]){
                if(marks[i] == 0){
                    if(dfs(graph, marks, stacked, i, m)==false)
                        return false;
                }else if(stacked[i]){
                    return false;
                }
            }
        }
        stacked[v] = 0;
        return true;
    }
    
};
// @lc code=end

