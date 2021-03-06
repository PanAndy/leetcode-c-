/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<iostream>
#include<deque>

using namespace std;


class MonotonicQueue{
    public: deque<int> data;

    void push(int n)
    {
        while(!data.empty() && data.back() < n){
            data.pop_back();
        }
        data.push_back(n);
    }

    int max(){
        return data.front();
    }

    void pop(int n)
    {
        if(!data.empty() && data.front() == n)
        {
            data.pop_front();
        }
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue window;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(i<k-1)
            {
                window.push(nums[i]);
            }else{
                window.push(nums[i]);
                res.push_back(window.max());
                window.pop(nums[i-k+1]);
            }
        }
        return res;
    }
};
// @lc code=end

