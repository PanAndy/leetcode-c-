/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    ListNode* cur = head;
            while(cur != NULL){
                ListNode* rear = cur->next;
                if(rear == NULL)
                    return head;
                if(cur->val == rear->val)
                    cur->next = rear->next;
                else
                    cur = cur->next;               
            }
            return head;
    }
};
// @lc code=end

