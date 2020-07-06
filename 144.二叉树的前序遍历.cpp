/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> path;
        dfs(root, path);
        return path;
    }

    void dfs(TreeNode* root, vector<int> &path)
    {
        if(root==NULL) return;
        path.push_back(root->val);
        dfs(root->left, path);
        dfs(root->right, path);
    }
};
// @lc code=end

