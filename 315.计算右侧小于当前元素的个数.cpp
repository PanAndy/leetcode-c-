/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> c;
    vector<int> a;

    void Init(int length){
        c.resize(length, 0);
    }

    int LowBit(int x){
        return x & (-x);
    }

    void Update(int pos)
    {
        while(pos < c.size())
        {
            c[pos] += 1;
            pos += LowBit(pos);
        }
    }

    int Query(int pos)
    {
        int ret = 0;
        while(pos>0){
            ret += c[pos];
            pos -= LowBit(pos);
        }
        return ret;
    }

    void Discretization(vector<int> &nums)
    {
        a.assign(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(),a.end()), a.end());
    }

    int getId(int x){
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        Discretization(nums);
        Init(nums.size()+5);
        for(int i=nums.size()-1;i>=0;--i)
        {
            int id = getId(nums[i]);
            res.push_back(Query(id-1));
            Update(id);
        }

        reverse(res.begin(), res.end());

        return res;
    }
    // vector<int> countSmaller(vector<int>& nums) {
    //     vector<int> counts(nums.size(), 0);

    //     for(int i=0;i<nums.size();i++)
    //     {
    //         int s = 0;
    //         for(int j=i+1;j<nums.size();j++)
    //         {
    //             if(nums[j] < nums[i])
    //             {
    //                 s++;
    //             }
    //         }
    //         counts[i] = s;
    //     }
    //     return counts;
    // }
};
// @lc code=end

