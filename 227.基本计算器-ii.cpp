/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int num = 0;
        char sign = '+';
        for(int i = 0;i<s.size();i++)
        {
            char c = s[i];            
            if(isdigit(c)){
                num = 10 * num + (c - '0');
            }

            if((!isdigit(c) && c!=' ' ) || i == s.size() - 1){
                // sign 保存的还是前一个的计算符号
                switch(sign){
                    int pre;
                    case '+':
                        stk.push(num);break;
                    case '-':
                        stk.push(-num);break;
                    case '*':
                        pre = stk.top();
                        stk.pop();
                        stk.push(pre * num);
                        break;
                    case '/':
                        pre = stk.top();
                        stk.pop();
                        stk.push(pre / num);
                        break;
                }
                sign = c;
                num = 0;
            }
        }
        int ans = 0;
        while (!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        return ans;        
    }
};
// @lc code=end

