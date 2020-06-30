/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

// @lc code=start
/**
 Definition for a binary tree node.*/

#include<iostream>
#include<vector>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pos = postorder.size()-1;
        return rebuild(inorder, postorder, pos, 0, inorder.size()-1);
    }

    TreeNode* rebuild(vector<int>& inorder, vector<int>& postorder, int &pr, int il, int ir)
    {
        if(pr<0)return NULL;
        if(il>ir)return NULL;
        int val = postorder[pr--];
        TreeNode* root = new TreeNode(val);

        int pos = il;
        for(;pos<=ir;++pos)
        {
            if(inorder[pos]==val)break;
        }

        root->right = rebuild(inorder, postorder, pr, pos + 1, ir);
        root->left = rebuild(inorder, postorder, pr, il, pos - 1);
        return root;
    }

};
// @lc code=end

