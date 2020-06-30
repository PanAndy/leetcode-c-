/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * */
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };

 
class Codec {
public:

    // Encodes a tree to a single string.
    
    string serialize(TreeNode* root) {
        v.clear();
        dfs(root);
        string ans;
        ans.push_back('[');
        for(int i=0;i<v.size();i++)
        {
            ans+=v[i];
            if(i!=v.size()-1)
            {
                ans+=",";
            }
        }
        ans.push_back(']');
        // cout<<ans<<endl;
        return ans;
    }

    vector<string> v;
    void dfs(TreeNode* root)
    {
        if(root==NULL)
        {
            v.push_back("#");
            return;
        }
        stringstream ss;
        ss<<root->val;
        // cout<<ss.str()<<endl;
        v.push_back(ss.str());
        dfs(root->left);
        dfs(root->right);
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        v.clear();
        for(int i=1, front=0;i<data.size();i++)
        {
            if(data[i]==','||data[i]==']')
            {
                string s = data.substr(front+1, i-front-1);
                // cout<<s<<endl;
                v.push_back(s);
                front = i;
            }
        }
        int pos = 0;
        TreeNode* root = rebuild(pos);
        return root;
    }

    TreeNode* rebuild(int &pos)
    {
        if(v[pos]=="#")
        {
            return NULL;
        }
        stringstream ss(v[pos]);
        int val = 0;
        ss >> val;
        // cout<<val<<endl;
        TreeNode* root = new TreeNode(val);
        if(root!=NULL)
        {
            root->left = rebuild(++pos);
            root->right = rebuild(++pos);
        }


        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

