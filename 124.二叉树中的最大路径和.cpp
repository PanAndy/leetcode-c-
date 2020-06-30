/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start

// Definition for a binary tree node.

#include<iostream>
#include<string>
#include<algorithm>
#include<climits>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };
class Solution {
public:

    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int l = max(dfs(root->left), 0);
        int r = max(dfs(root->right), 0 );
        int t = l + r + root->val;
        ans = max(ans, t);
        return root->val + max(l, r); //如果最大节点不是当前root，而是root以上的结点组成的，则当前root的路径只能是l和r当中的一个。  
    }
};
// @lc code=end

