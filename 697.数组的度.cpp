/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
#include<map>
#include<climits>
#include<vector>
using namespace std;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        struct node
        {
            int left=0;
            int right=0;
            int count=0;
        };
        map<int,node> m;
        node nd;
        int cnt_max = 1;
        int n = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end())
            {
                nd.left = i;
                nd.right = i;
                nd.count = 1;
                m[nums[i]]=nd;                
            }else{
                m[nums[i]].right = i;
                m[nums[i]].count++;

                if(m[nums[i]].count > cnt_max){
                    cnt_max =m[nums[i]].count;
                }
            }
        }
        for(auto i=m.begin();i!=m.end();i++){
            if((i->second).count==cnt_max){
                
                if(i->second.right - i->second.left + 1 < n){
                    n = i->second.right - i->second.left + 1;
                }
            }
        }

        return n;
    }
};
// @lc code=end

