/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     stack<int> s;
    //     int ans = 0;
    //     int current=0;
    //     while(current < n)
    //     {
    //         while (!s.empty() && height[current]>height[s.top()])
    //         {
    //             int top = s.top();
    //             s.pop();
    //             if(s.empty())break;
    //             int dis = current - s.top() - 1;
    //             int hei = min(height[current], height[s.top()]) - height[top];
    //             ans += dis * hei;
    //         }
            
    //         s.push(current++);
    //     }
    //     return ans;
    // }

    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l=0, r=n-1;
        int l_max = 0, r_max = 0;

        while(l < r)
        {
            if(height[l] < height[r])
            {
                height[l] >= l_max ? (l_max = height[l]) : ans += (l_max - height[l]);
                ++l;
            }else{
                height[r] >= r_max ? (r_max = height[r]) : ans += (r_max - height[r]);
                --r;
            }
        }

        return ans;
    }
};
// @lc code=end

