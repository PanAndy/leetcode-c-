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
        int i = m - 1, j = n - 1, r = m + n - 1;
        // if(n == 0)return;
        // if(m == 0){
        //     for(int s=0;s<n;s++)nums1[s] = nums2[s];
        //     return;
        // }
        while(i>=0 && j>=0)
        {
            if(nums1[i] < nums2[j])
            {
                nums1[r--] = nums2[j--];
            }else{
                nums1[r--] = nums1[i--];
            }
        }
        for(;i>=0&&r>=0;i--,r--)nums1[r] = nums1[i];
        for(;j>=0&&r>=0;j--,r--)nums1[r] = nums2[j];
    }

    void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, r = m;
        vector<int> tmp;
        while(i<m && j<n)
        {
            if(nums1[i] < nums2[j])
            {
                tmp.push_back(nums1[i++]);
            }else{
                tmp.push_back(nums2[j++]);
            }
        }
        for(;i<m;i++)tmp.push_back(nums1[i]);
        for(;j<n;j++)tmp.push_back(nums2[j]);
        nums1.assign(tmp.begin(), tmp.end());
    }

    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
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

