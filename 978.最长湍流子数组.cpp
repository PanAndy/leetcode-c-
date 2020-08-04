/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */

// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        vector<int> dp(A.size(), 0);
        dp[0] = 1;

        int flag = -1;
        int ans = dp[0];
        for(int i=1;i<A.size();i++)
        {
            if(A[i] > A[i-1])
            {
                if(flag == 0 || flag == -1)
                {
                    dp[i] = dp[i-1] + 1;
                }else{
                    dp[i] = 2;
                }
                flag = 1;
            }else if(A[i] < A[i-1])
            {
                if(flag == 1 || flag == -1){
                    dp[i] = dp[i-1] + 1;
                }else{
                    dp[i] = 2;
                }
                flag = 0;
            }else{
                flag = -1;
                dp[i] = 1;
            }
            // cout<<dp[i]<<endl;
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
// @lc code=end

