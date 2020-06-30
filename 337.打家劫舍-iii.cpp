/*
 @lc app=leetcode.cn id=337 lang=cpp
 *
 [337] 打家劫舍 III
 */

// @lc code=start
/**
 Definition for a binary tree node. */

#include<iostream>
#include<algorithm>
#include<map>
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

    int rob(TreeNode* root) {
        vector<int> ans = dp(root);
        return max(ans[0], ans[1]);
    }

    // 这个思路的核心是，用一个pair保存抢或者不抢能够获得的最大值
    vector<int> dp(TreeNode* root){
        if(root==NULL)return vector<int>(2, 0);
        vector<int> left = dp(root->left);
        vector<int> right = dp(root->right);

        int rob = root->val + left[0] + right[0];
        int not_rob = max(left[0],left[1]) + max(right[0], right[1]);
        vector<int> ans;
        ans.push_back(not_rob);
        ans.push_back(rob);
        return ans;
    }
    

    // map<TreeNode*,int> memo;
    // int rob(TreeNode* root) {
    //     memo.clear();
    //     return dfs(root);
    // }

    // int dfs(TreeNode* root)
    // {
    //     if(root==NULL)return 0;
    //     if(memo.find(root)!=memo.end()){
    //         return memo[root];
    //     }

    //     int do_it = root->val + 
    //                 (root->left==NULL ? 0 : rob(root->left->left)+rob(root->left->right)) +
    //                 (root->right==NULL ? 0 : rob(root->right->left) + rob(root->right->right));

    //     int not_do = rob(root->left) + rob(root->right);

    //     int res = max(do_it, not_do);
    //     memo[root] = res;
    //     return res;
    // }
};
// @lc code=end

