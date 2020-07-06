/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<ctime>

using namespace std;

#define randInt(m, n) rand()%(n - m) + n
class Solution {
public:

    vector<int> data;
    vector<int> shuffle_data;
    Solution(vector<int>& nums) {
        data.assign(nums.begin(), nums.end());
        shuffle_data = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        shuffle_data.clear();
        shuffle_data.assign(data.begin(), data.end());
        return shuffle_data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        // srand(unsigned(time(NULL)));
        int n = shuffle_data.size();

        for(int i=n-1;i>=0;i--)
        {
            int idx = rand() % (i + 1);
            swap(shuffle_data[i], shuffle_data[idx]);
        }
        return shuffle_data;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

