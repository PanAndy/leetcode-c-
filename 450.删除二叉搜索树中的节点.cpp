/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

// @lc code=start
/**
 * Definition for a binary tree node. */
#include<iostream>
#include<algorithm>
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;

        if(root->val==key){
            if(root->left==NULL && root->right==NULL)return NULL;

            if(root->left==NULL) return root->right;
            if(root->right==NULL) return root->left;

            TreeNode* right_min = getMin(root->right);

            root->val = right_min->val;
             
            root->right = deleteNode(root->right, right_min->val);
            return root;

        }else if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }else{
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
    TreeNode* getMin(TreeNode* root){
        
        TreeNode* tmp = root;
        while(tmp->left!=NULL)
        {
            tmp = tmp->left;
        }
        return tmp;
    }
};
// @lc code=end

