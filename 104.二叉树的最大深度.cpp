/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int l=0,r=0;
        l = maxDepth(root->left);
        r = maxDepth(root->right);
        return max(l,r)+1;
    }
};
// @lc code=end

