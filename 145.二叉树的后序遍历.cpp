/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
#include<vector>
#include<iostream>

using namespace std;
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> path;
        dfs(root, path);
        return path;
    }

    void dfs(TreeNode* root, vector<int> &path)
    {
        if(root==NULL) return;
        dfs(root->left, path);
        dfs(root->right, path);
        path.push_back(root->val);
    }
};
// @lc code=end

