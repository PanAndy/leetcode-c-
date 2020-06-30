/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0 , n = nums.size(), end = 0 , step = 0;
        for(int i=0;i<n-1;i++)
        {
            if(i<=maxPos)
            {
                maxPos = max(maxPos, i + nums[i]);
                if(i == end)
                {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }

    // int jump(vector<int>& nums) {
        

    //     int m = 0;
    //     int n = nums.size();
    //     int flag = 0;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(nums[i]!=1)
    //         {
    //             flag = 1;
    //         }
    //     }
    //     if(flag==0)return n-1;
    //     int i = n-1;
    //     while(i>0)
    //     {
    //         int m_to_now = n;
    //         for(int j = i-1;j>=0;--j)
    //         {
    //             if(i-j<=nums[j])
    //             {
    //                 m_to_now = min(m_to_now, j);
    //             }
    //         }
    //         i = m_to_now;
    //         m++;
    //     }

    //     return m;
    // }

    // int jump(vector<int>& nums) {

    //     int m = 0;
    //     int n = nums.size();
    //     int i = n-1;
    //     while(i>0)
    //     {
    //         int m_to_now = n;
    //         for(int j = i-1;j>=0;--j)
    //         {
    //             if(i-j<=nums[j])
    //             {
    //                 m_to_now = min(m_to_now, j);
    //             }
    //         }
    //         i = m_to_now;
    //         m++;
    //     }

    //     return m;
    // }


    // int jump(vector<int>& nums) {
    //     m = INT_MAX;
    //     dfs(nums, 0, 0);
    //     return m;
    // }

    // int m = INT_MAX;
    // void dfs(vector<int> nums, int pos, int jump_num)
    // {
    //     if(pos==nums.size()-1)
    //     {
    //         m = min(m, jump_num);
    //         return;
    //     }
    //     if(pos>nums.size()-1)
    //     {
    //         return;
    //     }

    //     for(int i=1;i<=nums[pos];i++)
    //     {
    //         dfs(nums, pos+i, jump_num+1);
    //     }
    // }

};
// @lc code=end

