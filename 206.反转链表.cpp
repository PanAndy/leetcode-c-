/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start

//Definition for singly-linked list.

#include<iostream>
#include<algorithm>

using namespace std;

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
//  };

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {

//         ListNode *p = head;

//         ListNode *cur=NULL;
//         while(p!=NULL){
//             ListNode *q = new ListNode(p->val);
//             q->next = cur;
//             cur = q;
//             p = p->next;
//         }
//         return cur;
//     }
// };
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head==NULL){
//             ListNode *p=NULL;
//             return p;
//         }

//         ListNode *q = reverseList(head->next);
        
//         if(q == NULL){
//             q = new ListNode(head->val);
//         }else{
//             ListNode *cur = q;
//             while(cur->next!=NULL){
//                 cur = cur->next;
//             }
//             cur->next = new ListNode(head->val);
//         }
//         return q;
//     }
// };
class Solution {
public:
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* cur=head;
    //     ListNode* pre=NULL;
    //     ListNode* temp;
    //     while(cur!=NULL){
    //         temp = cur->next;
    //         cur->next=pre;
    //         pre=cur;
    //         cur=temp;
    //     }
    //     return pre;
    // }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return head;
        if(head->next==NULL)return head;
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
};
// @lc code=end

