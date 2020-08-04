/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n==0)return 0;
        sort(envelopes.begin(),envelopes.end(), cmp);
        vector<int> height(n, 0);
        for(int i=0;i<n;i++)height[i] = envelopes[i][1];

        vector<int> dp(n, 1);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(height[i] > height[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            ans = max(ans, dp[i]);
        }        
        return ans;
    }

    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0]==b[0] ? a[1] > b[1] : a[0] < b[0];
    }

    // static bool cmp(vector<int> &a, vector<int> &b){
    //     return a[0]==b[0] ? a[1] > b[1] : a[0] < b[0];
    // }
    // int maxEnvelopes(vector<vector<int>>& envelopes) {
    //     int n = envelopes.size();
    //     sort(envelopes.begin(), envelopes.end(), cmp);

    //     vector<int> height(n, 0);
    //     for(int i=0;i<n;i++) height[i] = envelopes[i][1];
    //     return lengthOfLIS(height);
    // }

    // int lengthOfLIS(vector<int> nums){
    //     int piles = 0, n = nums.size();
    //     vector<int> top(n, 0);
    //     for(int i=0;i<n;++i)
    //     {
    //         int poker = nums[i];
    //         int left = 0, right = piles;

    //         while(left < right)
    //         {
    //             int mid = (left + right) / 2;
    //             if(top[mid] >= poker){
    //                 right = mid;
    //             }else{
    //                 left = mid + 1;
    //             }
    //         }
    //         if(left == piles) piles++;
    //         top[left] = poker;
    //     }
    //     return piles;
    // }
};
// @lc code=end

