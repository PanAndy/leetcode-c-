/*
 * @lc app=leetcode.cn id=1028 lang=cpp
 *
 * [1028] 从先序遍历还原二叉树
 */

// @lc code=start

//  Definition for a binary tree node.

#include<iostream>
#include<string>
#include<stack>

using namespace std;

// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        if(S.empty())return NULL;
        stack<TreeNode*> path;
        int pos = 0;
        while(pos<S.size()){
            int level = 0;
            while (S[pos]=='-')
            {
                ++level;
                ++pos;
            }
            int value = 0;
            while(pos<S.size() && isdigit(S[pos]))
            {
                value = value * 10 + (S[pos]-'0');
                ++pos;
            }
            TreeNode* node = new TreeNode(value);
            if(level == path.size())
            {
                if(!path.empty())
                {
                    path.top()->left = node;
                }
            }else{
                while(level!=path.size())
                    path.pop();
                path.top()->right = node;
            }
            path.push(node);
        }
        while(path.size()>1)
            path.pop();
        return path.top();
    }
};
// @lc code=end

