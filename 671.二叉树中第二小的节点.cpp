/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
 */

// @lc code=start
/**
 * Definition for a binary tree node. */

#include<iostream>
#include<climits>
#include<algorithm>
#include<list>
using namespace std;

//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL)return -1;
        if(root->left!=NULL){
            int val = root->val;
            int rval = root->right->val;
            int lval = root->left->val;
            if(val==rval){
                rval = findSecondMinimumValue(root->right);
            }
            if(val==lval){
                lval = findSecondMinimumValue(root->left);
            }
            if(rval==-1 && lval==-1)return -1;
            else if(rval!=-1 && lval==-1){
                return rval;
            }
            else if(rval==-1 && lval!=-1){
                return lval;
            }else{
                vector<int> v;
                v.push_back(val);
                v.push_back(rval);
                v.push_back(lval); 
                sort(v.begin(),v.end());
                return v[1];
            }           
        }
        return -1;
    }
};
// @lc code=end

