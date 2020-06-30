/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
#include<iostream>
#include<string>
#include<sstream>

using  namespace std;

class Solution {
public:

    string countAndSay(int n) {
        string s="1";
        for(int i=0;i<n-1;i++)
        {
            string last=s.substr(0,1);
            int cnt=1;
            string tmp;
            stringstream ss(tmp);
            for(int j=1;j<s.size();j++){
                if(s.substr(j,1)==last){
                    cnt++;
                }else{
                    ss<<cnt<<last;
                    last=s[j];
                    cnt=1;
                }
            }
            if(tmp.empty()){
                //cout<<cnt<<last<<endl;
                ss<<cnt<<last;
            }
            tmp = ss.str();
            s = tmp;
        }
        return s;
    }
};
// @lc code=end

