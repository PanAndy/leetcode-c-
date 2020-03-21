/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());

        int res=0;
        
        for(int j=0,i=0;j<s.size()&&i<g.size();++j){
            if(s[j]>=g[i]){
                ++i;
                ++res;
            }
        }
        
        return res;
    }
};
// @lc code=end

