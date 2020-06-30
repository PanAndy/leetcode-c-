/*
 @lc app=leetcode.cn id=99 lang=cpp
 *
 [99] 恢复二叉搜索树
 */

// @lc code=start
/**
 Definition for a binary tree node.*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };


class Solution {
public:
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(x->val, y->val);
    }


    TreeNode* pre;
    TreeNode* x;
    TreeNode* y;
    void dfs(TreeNode* root)
    {
        if(root==NULL) return;

        dfs(root->left);

        if(pre==NULL){
            pre = root;
        }else{
            if(root->val < pre->val)
            {
                y = root;
                if(x==NULL)
                {
                    x = pre;
                }
            }
        }
        pre = root;
        dfs(root->right);
    }

};
// @lc code=end

