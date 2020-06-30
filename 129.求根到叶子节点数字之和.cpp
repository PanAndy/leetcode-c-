/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
#include<vector>
#include<iostream>

using namespace std;
class Solution {
public:
    int ans = 0;
    vector<vector<int> > v;
    int sumNumbers(TreeNode* root) {
        if(root==NULL)return 0;
        v.clear();
        ans = 0;
        vector<int> s;
        dfs(root, s);
        for(int i=0;i<v.size();++i)
        {
            int tmp = 0;
            for(int j=v[i].size()-1;j>=0;--j)
            {
                tmp += v[i][j]*(pow(10, v[i].size()-1-j));
            }
            // cout<<tmp<<endl;
            ans += tmp;
        }
        return ans;
    }

    void dfs(TreeNode* root, vector<int> s)
    {
        if(root==NULL)return;
        s.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            v.push_back(s);
            return;
        }
        if(root->left!=NULL)
            dfs(root->left, s);
        
        if(root->right!=NULL)
            dfs(root->right, s);
        s.pop_back();
    }

};
// @lc code=end

