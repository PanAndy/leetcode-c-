/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node. */
#include<iostream>
#include<vector>

using namespace std;

//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())return NULL;
        vector<int> vector_l(nums.begin(),nums.begin()+nums.size()/2);
        vector<int> vector_r(nums.begin()+nums.size()/2+1,nums.end());

        TreeNode * root = new TreeNode(nums[nums.size()/2]);

        root->left = sortedArrayToBST(vector_l);
        root->right = sortedArrayToBST(vector_r);

        return root;
    }
};
// @lc code=end

