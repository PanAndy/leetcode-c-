/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* successor = NULL;
    ListNode* reverseN(ListNode* head, int n){
        if(n==1){
            successor = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = successor;
        return last;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==1){
            return reverseN(head, n);
        }
        head->next = reverseBetween(head->next, m-1, n-1);
        return head;
    }
};
// @lc code=end

