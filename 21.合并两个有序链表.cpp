/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list. */

#include<iostream>
#include<algorithm>
using namespace std;

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL&&l2!=NULL)return l2;
        if(l1!=NULL&&l2==NULL)return l1;
        if(l1==NULL&&l2==NULL)return NULL;

        ListNode *p=l1, *q=l2;
        ListNode *head = new ListNode(min(l1->val,l2->val));
        ListNode *h=head;
        while(true){
            if(p==NULL){
                head->next = q;
                break;
            }else if(q==NULL){
                head->next = p;
                break;
            }

            if(p->val < q->val){
                head->next = new ListNode(p->val);
                p = p->next;
            }else{
                head->next = new ListNode(q->val);
                q = q->next;
            }
            head = head->next;
        }

        return h->next;
    }
};
// @lc code=end

