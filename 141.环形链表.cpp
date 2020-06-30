/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
#include<iostream>
#include<map>
using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)return false;
        ListNode *fast = head, *slow = head;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
            
        }
        return false;

    }
    // bool hasCycle(ListNode *head) {
    //     if(head==NULL)return false;
    //     ListNode* p = head;
    //     map<ListNode*, int> m;
    //     while (p!=NULL)
    //     {
    //         if(m.count(p)==0)
    //         {
    //             m[p]=1;
    //         }else{
    //             return true;
    //         }
    //         p = p->next;
    //     }
    //     return false;
    // }
};
// @lc code=end

