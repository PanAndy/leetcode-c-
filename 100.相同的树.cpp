/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start

// Definition for a binary tree node.

#include<iostream>

using namespace std;

//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p!=NULL && q==NULL || p==NULL &&q!=NULL)return false;
        if(p==NULL && q==NULL)return true;
        
        bool res = p->val == q->val;
        if(res && isSameTree(p->left,q->left))
        {
            if(isSameTree(p->right,q->right)){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

