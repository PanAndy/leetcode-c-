/*
@lc app=leetcode.cn id=83 lang=cpp
 *
[83] 删除排序链表中的重复元素
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
    // ListNode* deleteDuplicates(ListNode* head) {
    //     ListNode* cur = head;
    //     while(cur != NULL){
    //         ListNode* rear = cur->next;
    //         if(rear == NULL)
    //             return head;
    //         // 严重的内存泄漏啊
    //         if(cur->val == rear->val){
    //             cur->next = rear->next;
    //             delete rear;
    //         }
    //         else
    //             cur = cur->next;               
    //     }
    //     return head;
    // }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;

        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast!=NULL)
        {
            if(slow->val!=fast->val){
                slow = slow->next;
                slow->val = fast->val;
            }
            fast = fast->next;
        }
        ListNode* p = slow->next;
        slow->next = NULL;
        while(p!=NULL)
        {
            auto t = p->next;
            delete p;
            p = t;
        }
        return head;
    }
};
// @lc code=end

