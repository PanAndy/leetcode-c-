/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        if(n==0)return {};
        vector<int> ans;
        int idx1 = 0;
        int idx2 = n - 1;
        while(idx1 < idx2){
            int s = numbers[idx1] + numbers[idx2];
            if(s == target){
                ans.push_back(idx1+1);
                ans.push_back(idx2+1);
                break;
            }else if(s < target){
                idx1++;
            }else if(s > target){
                idx2--;
            }
        }
        return ans;
    }
};
// @lc code=end

