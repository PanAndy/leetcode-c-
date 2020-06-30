/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v{-1, -1};
        
        int n = nums.size();
        if(n==0)return v;
        if(n==1){
            if(nums[0]==target){
                v[0]=0;
                v[1]=0;
                return v;
            }else{
                return v;
            }
        }

        int l=0,r=n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]==target)
            {
                if(mid==0 || nums[mid-1]!=target)
                {
                    v[0]=mid;
                    break;
                }else{
                    r = mid-1;
                }
            }
            if(nums[mid]<target)
            {
                l = mid + 1;
            }else if(nums[mid]> target)
            {
                r = mid - 1;
            }
        }
        l = 0 ;
        r = n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]==target)
            {
                if(mid==n-1 || nums[mid+1]!=target)
                {
                    v[1]=mid;
                    break;
                }else{
                    l = mid + 1;
                }

            }

            if(nums[mid]<target)
            {
                l = mid + 1;
            }else if(nums[mid]> target)
            {
                r = mid - 1;
            }
        }

        return v;
    }
};
// @lc code=end

