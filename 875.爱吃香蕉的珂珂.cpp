/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1;
        int right = 0;
        for(int i : piles){
            right = max(right, i);
        }
        ++right;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            // cout<<mid<<endl;
            if(canfinish(piles, mid, H)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }

    bool canfinish(vector<int> piles, int speed, int H)
    {
        int time = 0;
        for(int n : piles){
            int t = (n / speed) + ((n % speed > 0) ? 1 : 0);
            // cout<<t<<endl;
            // cout<<n<<endl;
            time+=t;
        }
        // cout<<time<<endl;
        // cout<<speed<<endl;
        return time <= H;
    }
};
// @lc code=end

