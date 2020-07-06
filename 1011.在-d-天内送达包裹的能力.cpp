/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0;
        for(int i : weights){
            left = max(left, i);
        }
        int right = 1;
        for(auto i : weights){
            right += i;
        }

        while(left < right)
        {
            int mid = left + (right - left) / 2;

            if(OK(weights, mid, D)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }

    bool OK(vector<int> &weight, int cap, int D)
    {
        int days = 1;
        int huowu = 0;
        for(auto i : weight)
        {
            if(huowu+i <= cap)
            {
                huowu+=i;;
            }else{
                days++;
                huowu = i;
            }
        }
        return days <= D;
    }
};
// @lc code=end

