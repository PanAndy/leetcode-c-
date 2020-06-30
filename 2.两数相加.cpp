/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start

// Definition for singly-linked list.
#include<iostream>
#include<vector>

using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;

        ListNode *ans=NULL, *q=NULL;

        ListNode *first = l1, *second = l2;

        int flag = 0;
        while(first!=NULL || second!=NULL)
        {
            int l=0,r=0;
            if(first==NULL)
            {
                l = 0;
            }else{
                l = first->val;
            }

            if(second==NULL)
            {
                r = 0;
            }else{
                r = second->val;
            }

            int add = (l + r + flag) % 10;
            flag = (l + r + flag) / 10;

            ListNode *p = new ListNode(add);
            if(ans==NULL)
            {
                ans = p;
                q = p;
            }else{
                q->next = p;
                q = p;     
            }
            if(first!=NULL)
                first = first->next;
            if(second!=NULL)
                second = second->next;
        }

        if(flag>0)
        {
            ListNode *p = new ListNode(flag);
            q->next = p;
        }

        return ans;

    }
};
// @lc code=end

