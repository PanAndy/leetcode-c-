/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0 || nums2.size()==0)return {};
        map<int,int> m;
        for(int i : nums1){
            m[i]++;
        }
        vector<int> ans;
        for(int i : nums2)
        {
            if(m[i] > 0){
                m[i]--;
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

