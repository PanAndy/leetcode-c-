/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int l = INT_MAX, r = INT_MAX;
        if(root->left!=NULL) l = minDepth(root->left);
        else l = INT_MAX;
        if(root->right!=NULL) r = minDepth(root->right);
        else r = INT_MAX;

        if(l==INT_MAX && r==INT_MAX)return 1;
        return min(l,r)+1;
    }

    int mDepth(TreeNode* root) {
            if(root==NULL)return 0;
            int l = mDepth(root->left);
            int r = mDepth(root->right);
            return min(l,r)+1;
        }

};
// @lc code=end

