/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node. */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int lh = height(root->left);
        int rh = height(root->right);   
        return (abs(lh-rh)<=1)&&isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode* root){
        if(root==NULL)return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return max(lh,rh) + 1;
    }
};
// @lc code=end

