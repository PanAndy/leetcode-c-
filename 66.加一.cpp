/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        vector<int> ans;
        ans.push_back(0);
        for(int i=0;i<digits.size();i++)
            ans.push_back(digits[i]);
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(ans[i]+1>9){
                ans[i]=0;                
            }else{
                ans[i] += 1;
                break;
            }
        }
        
        if(ans[0]==1){
            return ans;
        }else{
            vector<int> ans2;
            for(int i=1;i<=ans.size()-1;i++){
                ans2.push_back(ans[i]);
            }
            return ans2;
        }
    }
};
// @lc code=end

