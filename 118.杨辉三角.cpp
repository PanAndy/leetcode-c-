/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        if(numRows==0)return ans;
        vector<int> init{1};
        ans.push_back(init);
        for(int i=2;i<=numRows;++i)
        {
            vector<int> n(i, 0);
            for(int j=0;j<n.size();++j)
            {
                int l = j-1==-1 ? 0 : init[j-1];
                int r = j==i-1 ? 0 : init[j];
                n[j] = l + r;
            }
            ans.push_back(n);
            init.clear();
            init.assign(n.begin(),n.end());
        }
        return ans;
    }
};
// @lc code=end

