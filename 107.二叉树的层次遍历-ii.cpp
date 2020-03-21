/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 *  */

#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;
// struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > vv;
        if(root==NULL)return vv;
        stack<vector<int> > s;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){        
            vector<int> v;
            queue<TreeNode *> tree;
            while(!q.empty()){
                TreeNode * front = q.front();
                v.push_back(front->val);
                q.pop(); 
                if(front->left!=NULL){
                    tree.push(front->left);
                }
                if(front->right!=NULL){
                    tree.push(front->right);
                }
            }
            s.push(v);
            q = tree;            
        }

        while(!s.empty()){
            vv.push_back(s.top());
            s.pop();
        }
        return vv;
    }
};
// @lc code=end

