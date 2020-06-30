/*
@lc app=leetcode.cn id=98 lang=cpp
 *
[98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        return isVal(root, NULL, NULL);
    }

    bool isVal(TreeNode* root, TreeNode* MIN, TreeNode* MAX)
    {
        if(root==NULL)return true;
        if(MIN!=NULL && root->val<=MIN->val) return false;
        if(MAX!=NULL && root->val>=MAX->val)return false;
        return isVal(root->left, MIN, root) && isVal(root->right, root, MAX);

    }

};
// @lc code=end

