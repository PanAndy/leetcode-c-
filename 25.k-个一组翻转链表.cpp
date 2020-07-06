/*
@lc app=leetcode.cn id=25 lang=cpp
 *
[25] K 个一组翻转链表
 */

// @lc code=start
/**
Definition for singly-linked list. */
#include<iostream>
#include<algorithm>

using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)return NULL;
        ListNode *a=head, *b=head;
        for(int i=0;i<k;i++)
        {
            if(b==NULL)return head;
            b = b->next;
        }
        ListNode* newhead = reverse(a, b);
        a->next = reverseKGroup(b, k);
        return newhead;
    }

    ListNode* reverse(ListNode* a, ListNode* b){
        ListNode *pre=NULL, *cur=a, *next=a;
        while (cur!=b)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre; 
    }

};
// @lc code=end

