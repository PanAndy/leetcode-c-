/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// @lc code=start

 // Definition for a binary tree node.

 #include<iostream>

 using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return false;
        }       
        if(root->left==NULL && root->right==NULL && root->val==sum)return true;
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);           
    }
};
// @lc code=end

