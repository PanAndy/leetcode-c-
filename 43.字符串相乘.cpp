/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> res(m+n, 0);

        for(int i=m-1;i>=0;--i)
        {
            for(int j=n-1;j>=0;--j)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j;
                int p2 = i + j + 1;
                int s = mul + res[p2];
                res[p2] = s % 10;
                res[p1] += s / 10;
            }
        }
        int i = 0;
        while (i < res.size() && res[i] == 0)
        {
            i++;
        }
        string ans;
        for(; i<res.size();++i){
            ans.push_back(res[i]+'0');
        }
        return ans.size()==0 ? "0" : ans;
    }
};
// @lc code=end

