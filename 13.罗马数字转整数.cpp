/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include<iostream>
#include<string>
#include<map>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<string,int> m;
        m["I"] = 1;
        m["V"] = 5;
        m["X"] = 10;
        m["L"] = 50;
        m["C"] = 100;
        m["D"] = 500;
        m["M"] = 1000;     
        m["IV"] = 4;
        m["IX"] = 9;
        m["XL"] = 40;
        m["XC"] = 90;
        m["CD"] = 400;
        m["CM"] = 900;


        if((s=="IV"||s=="IX"||s=="XL"||s=="XC"||s=="CD"||s=="CM"))
        {
            return m[s];
        }

        int i=0;
        for(;i<s.size();i++){
            if(s[i]=='I'&&i<s.size()-1&&(s[i+1]=='V'||s[i+1]=='X')){
                ans += m[s.substr(i,2)];
                i++;
            }
            else if(s[i]=='X'&&i<s.size()-1&&(s[i+1]=='L'||s[i+1]=='C')){
                ans += m[s.substr(i,2)];
                i++;
            }
            else if(s[i]=='C'&&i<s.size()-1&&(s[i+1]=='D'||s[i+1]=='M')){
                ans += m[s.substr(i,2)];
                i++;
            }else
            {
                ans += m[s.substr(i,1)];
            }           
        }
        return ans;
    }
};
// @lc code=end

