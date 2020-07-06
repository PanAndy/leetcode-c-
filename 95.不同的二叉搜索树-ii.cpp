/*
@lc app=leetcode.cn id=95 lang=cpp
 *
[95] 不同的二叉搜索树 II
 */

// @lc code=start
/**
Definition for a binary tree node. */

#include<iostream>
#include<vector>

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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            return vector<TreeNode*>();
        }
        return gT(1, n);
    }
    vector<TreeNode*> gT(int start, int end)
    {
        vector<TreeNode*> all_trees;
        if(start > end)
        {
            all_trees.push_back(NULL);
            return all_trees;
        }

        for(int i=start; i<=end;++i){
            vector<TreeNode*> left_tress = gT(start, i-1);
            vector<TreeNode*> right_tress = gT(i+1, end);
            for(auto l : left_tress){
                for(auto r : right_tress){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    all_trees.push_back(root);
                }
            }
        }
        return all_trees;
    }
};
// @lc code=end

