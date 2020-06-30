/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

// 这一题的最显著的特点就是，细节特别多，可以多拿来练练手！锤炼思维！


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;

        sort(nums.begin(),nums.end());

        int len = nums.size();
        for(int i=0;i<len-2;i++){
            if(i==0||(i>0&&nums[i]!=nums[i-1])){
                int p1 = i + 1;
                int p2 = len - 1;
                while(p1<p2){
                    if(nums[p1]>-nums[i])break;
                    if(p1>i+1&&nums[p1]==nums[i] || nums[p1]+nums[p2]<-nums[i]){
                        p1++;
                    }
                    else if(p2<len-1&&nums[p2]==nums[p2+1] || nums[p1]+nums[p2]>-nums[i]){
                        p2--;
                    }else{
                        vector<int> vtemp{nums[i],nums[p1],nums[p2]};
                        ans.push_back(vtemp);
                        vtemp.clear();
                        p1++;
                        p2--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

