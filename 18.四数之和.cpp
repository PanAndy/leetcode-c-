/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using  namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > v; 
        if(nums.size()<4)return v;

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-3;i++){
            if(i==0 || i>0&&nums[i]!=nums[i-1])
            {
                int t = target - nums[i];

                for(int j=i+1;j<nums.size()-2;j++){
                    if(j==i+1 || j>i+1 && nums[j]!=nums[j-1]){
                        int l=j+1;
                        int r=nums.size()-1;
                        while(l<r){
                            if(nums[l]+nums[r]+nums[j]<t){
                                l++;
                            }else if(nums[l]+nums[r]+nums[j]>t){
                                r--;
                            }else{
                                if(l!=j+1 && nums[l]==nums[l-1]){
                                    l++;
                                }
                                else if((r<nums.size()-1 && nums[r]==nums[r+1]))
                                {
                                    r--;
                                }else{
                                vector<int> temp{nums[i],nums[j],nums[l],nums[r]};
                                v.push_back(temp);
                                temp.clear();
                                l++;
                                r--;}
                            }
                        }
                    }
                }
            }
        }
        return v;
    }
};
// @lc code=end

