/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m + n - 1;

        int i1=m-1,i2=n-1;

        while(idx>=0){
            if(i1==-1){
                for(int i=i2;i>=0;i--){
                    nums1[idx--] = nums2[i];
                }
                break;
            }
            if(i2==-1){
                for(int i=i1;i>=0;i--){
                    nums1[idx--] = nums1[i];
                }
                break;
            }

            if(nums1[i1]>=nums2[i2]){
                nums1[idx--] = nums1[i1--];
            }else{
                nums1[idx--] = nums2[i2--];
            }
        }
    }
};
// @lc code=end

