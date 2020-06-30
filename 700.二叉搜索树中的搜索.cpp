/*
@lc app=leetcode.cn id=700 lang=cpp
 *
[700] 二叉搜索树中的搜索
 */

// @lc code=start
/**
Definition for a binary tree node. */

#include<iostream>
#include<algorithm>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        if(root->val == val) return root;
        else if(root->val < val)
        {
            return searchBST(root->right, val);
        }else{
            return searchBST(root->left, val);
        }
        // return NULL;
    }
};
// @lc code=end

