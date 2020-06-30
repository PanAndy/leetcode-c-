/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */

#include<iostream>
#include<vector>

using namespace std;

//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        zhong.clear();
        inv_zhong.clear();
        inorder(root);
        inv_inorder(root);

        bool flag = true;
        for(int i=0;i<zhong.size();i++)
        {
            if(zhong[i]!=inv_zhong[i]){
                flag = false;
                break;
            }
        }
        return flag;
    }

    vector<int> zhong;
    vector<int> inv_zhong;

    void inorder(TreeNode* root)
    {
        if(root==NULL){
            zhong.push_back(-1);
            return;
        };
        inorder(root->left);
        inorder(root->right);
        zhong.push_back(root->val);
    }

    void inv_inorder(TreeNode *root)
    {
        if(root==NULL){
            inv_zhong.push_back(-1);
            return;
        };
        inv_inorder(root->right);
        inv_inorder(root->left);
        inv_zhong.push_back(root->val);
    }

};
// @lc code=end

