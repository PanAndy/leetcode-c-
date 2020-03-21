/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start

#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(int i=0;i<ops.size();i++){
            if((ops[i][0]>='0' && ops[i][0]<='9') || (ops[i][0] == '-')){
                stringstream ss(ops[i]);
                int score=0;
                ss>>score;
                s.push(score);
            }
            else if(ops[i][0]=='C'){
                s.pop();
            }else if(ops[i][0]=='D'){
                s.push(s.top()*2);
            }else if(ops[i][0]=='+'){
                int t1 = s.top();
                s.pop();
                int t2 = s.top() + t1;
                s.push(t1);
                s.push(t2);
            }
        }
        int sum = 0;
        while(!s.empty()){
            sum+=s.top();
            s.pop();
        }
        return sum;
    }
};
// @lc code=end

