/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Employee info
*/
#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

// class Employee {
// public:
//     // It's the unique ID of each node.
//     // unique id of this employee
//     int id;
//     // the importance value of this employee
//     int importance;
//     // the id of direct subordinates
//     vector<int> subordinates;
// };

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int s=0;
        map<int,Employee*> m;
        for(int i=0;i<employees.size();i++){
            m[employees[i]->id] = employees[i];
        }

        queue<Employee*> q;
        q.push(m[id]);
        s += m[id]->importance;
        while(!q.empty()){
            Employee * front = q.front();
            q.pop();
            vector<int> sub = front->subordinates;

            for(int i=0;i<sub.size();i++){
                s = s + m[sub[i]]->importance;
                q.push(m[sub[i]]);
            }
        }

        return s;
    }
};
// @lc code=end

