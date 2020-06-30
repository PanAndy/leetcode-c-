/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
/**
 Definition for a binary tree node.*/
#include<iostream>
#include<algorithm>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos = 0;
        return rebuild(preorder, inorder, pos, 0, preorder.size()-1);
    }

    TreeNode* rebuild(vector<int>& preorder, vector<int>& inorder, int &pl, int il, int ir)
    {
        if(pl > preorder.size()-1)return NULL;
        if(il>ir)return NULL;
        int val = preorder[pl++];
        TreeNode* root = new TreeNode(val);

        int pos = il;
        for(int i = il; il<=ir; ++i,++pos)
        {
            if(inorder[i]==val)
            {
                break;
            }
        }

        root->left = rebuild(preorder, inorder, pl, il, pos-1);
        root->right = rebuild(preorder, inorder, pl, pos + 1, ir);
        return root;
    }
};
// @lc code=end

