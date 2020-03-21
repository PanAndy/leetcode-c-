/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start

//Definition for a binary tree node.

#include<iostream>

using namespace std;

//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return NULL;

        TreeNode *tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};
// @lc code=end

