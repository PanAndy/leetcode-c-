/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct cmp{
    int x;
    cmp(int t):x(t){}
    bool operator () (int y){
        return y > x;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums1.size();++i){
            auto pos_1 = find(nums2.begin(),nums2.end(),nums1[i]);
            int value = {nums1[i]};
            auto pos_2 = find_if(pos_1+1,nums2.end(),[value](int n){return n>value;});
            if(pos_2==nums2.end()){
                nums1[i] = -1;
            }else{
                nums1[i] = *pos_2;
            }
        }
        return nums1;
    }
};
// @lc code=end

