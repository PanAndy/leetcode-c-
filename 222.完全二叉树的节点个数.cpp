/*
@lc app=leetcode.cn id=222 lang=cpp
 *
[222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        TreeNode *l = root, *r = root;
        int hl = 0, hr = 0;
        while(l != NULL){
            l = l->left;
            hl++;
        } 
        while (r != NULL)
        {
            r = r->right;
            hr++;
        }
        if(hl == hr){
            return (int)pow(2, hl) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
        
    }
};
// @lc code=end

