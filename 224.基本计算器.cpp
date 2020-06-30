/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int operand = 0;
        int result = 0;
        int sign = 1;
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            if(isdigit(ch)){
                operand = 10 * operand + (int)(ch - '0');
            }else if(ch == '+'){
                result += sign * operand;
                sign = 1;
                operand = 0;
            }else if(ch == '-'){
                result += sign * operand;
                sign = -1;
                operand = 0;
            }else if(ch == '('){
                stk.push(result);
                stk.push(sign);
                sign = 1;
                result = 0;
            }else if(ch == ')'){
                result += sign * operand;
                result *= stk.top();//操作符
                stk.pop();
                result += stk.top();//操作数
                stk.pop();
                operand = 0;
            }
        }
        return result + (sign * operand);
    }
    // int helper(string s)
    // {
    //     stack<int> stk;
    //     int num = 0;
    //     char sign = '+';
    //     for(int i=0;i<s.size();i++){
    //         char c = s[i];
    //         if(isdigit(c)){
    //             num = 10*num + (c - '0');
    //         }
    //         if((!isdigit(c) && (c!=' '))|| i==s.size()-1){
    //             switch (sign)
    //             {
    //             case '+':
    //                 stk.push(num);
    //                 break;
                
    //             case '-':
    //                 stk.push(-num);
    //                 break;
    //             case '(':
                    
    //                 break;
    //             case ')': 
    //                 break;
    //             }
    //             sign = c;
    //             num = 0;
    //         }
    //     }
    //     int res = 0;
    //     while(!stk.empty()){
    //         res += stk.top();
    //         stk.pop();
    //     }
    //     return res;
    // }
};
// @lc code=end

