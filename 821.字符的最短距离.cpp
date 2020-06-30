/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> v(n, 0);

        for(int i=0;i<n;++i)
        {
            int pre = INT_MAX;
            for(int j = i;j<n;++j)
            {
                if(S[j] == C)
                {
                    pre = j - i;
                    break;
                }
            }
            int after = INT_MAX;
            for(int j = i; j>=0; --j)
            {
                if(S[j] == C)
                {
                    after = i - j;
                    break;
                }
            }
            v[i] = min(pre, after);
        }
        return v;
    }
};
// @lc code=end

