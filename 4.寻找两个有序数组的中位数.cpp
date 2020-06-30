/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if(m>n){
            swap(nums1,nums2);
            swap(m,n);
        }
        
        int iMin=0,iMax=m;
        int Half_len = (m+n+1)/2;
        while(iMin<=iMax){
            int i = (iMin + iMax)/2;
            int j = Half_len - i;

            if(i<iMax&&nums2[j-1]>nums1[i]){
                iMin = i + 1;
            }
            else if(i>iMin&&nums1[i-1]>nums2[j]){
                iMax = i - 1;
            }else{
                
                int max_left = 0;
                if(i==0){
                    max_left = nums2[j-1];
                }
                else if(j==0){
                    max_left = nums1[i-1];
                }
                else{
                    max_left = max(nums1[i-1],nums2[j-1]);
                }
                if((m+n)%2==1){
                    return max_left;
                }
                int max_right = 0;
                if(i==m){
                    max_right = nums2[j];
                }else if(j==n){
                    max_right = nums1[i];
                }else{
                    max_right = min(nums1[i],nums2[j]);
                }
                return (max_right+max_left)/2.0;
            }

        }

        return 0.0;
    }
};
// @lc code=end

