/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list. */
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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)return head;
        ListNode* fast = head;
        ListNode* slow = head;
        int flag = 0;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                flag = 1;
                break;
            }
        }
        
        slow = head;
        while (flag && fast!=slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return flag==0 ? NULL: fast;
    }
};
// @lc code=end

