/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list. */
#include<iostream>

using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL)return head;
        // 加一个虚拟结点，妙啊
        ListNode* p = new ListNode(0);
        p->next = head;
        ListNode* fast = p;
        ListNode* slow = p;
        for(int i=0;i<=n;i++)
            fast = fast->next;

        while(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;

        return p->next;
    }
};
// @lc code=end

