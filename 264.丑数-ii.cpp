/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Ugly{
public:
    vector<int> nums;

    Ugly(){
        nums = vector<int>(1690 + 10, 0);
        nums[0] = 1;
        int ugly, i2=0, i3=0, i5=0;

        for(int i=1;i<1690;++i){
            ugly = min(min(nums[i2]*2, nums[i3]*3), nums[i5]*5);
            nums[i] = ugly;

            if(ugly == nums[i2]*2) ++i2;
            if(ugly == nums[i3]*3) ++i3;
            if(ugly == nums[i5]*5) ++i5;
        }
    }

};

class Solution {
public:
    Ugly u = Ugly();
    int nthUglyNumber(int n) {
        return u.nums[n-1];
    }
};
// @lc code=end

