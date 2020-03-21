/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
 */

// @lc code=start

// Definition for a binary tree node.
#include<iostream>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL && t==NULL)return true;
        if(s!=NULL && t==NULL)return false;
        if(s==NULL && t!=NULL)return false;

        if(s->val==t->val)
        {
            if(isSameTree(s,t)){
                return true;
            }
        }
        return isSubtree(s->left,t)||isSubtree(s->right,t);       
    }

    bool isSameTree(TreeNode*s, TreeNode* t){
        if(s==NULL && t==NULL)return true;
        if(s!=NULL && t==NULL)return false;
        if(s==NULL && t!=NULL)return false;
        if(s->val==t->val){
            return isSameTree(s->left, t->left)&&isSameTree(s->right, t->right);
        }
        return false;

    }

};
// @lc code=end

