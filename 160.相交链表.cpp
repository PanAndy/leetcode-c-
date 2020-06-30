/*
@lc app=leetcode.cn id=160 lang=cpp
 *
[160] 相交链表
 */

// @lc code=start
/**
Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 */

#include<iostream>
#include<vector>
#include<map>
using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)return NULL;
        map<ListNode*, int> m;
        ListNode* p = headA;
        while (p!=NULL)
        {
            m[p]=1;
            p = p->next;
        }
        p = headB;
        while(p!=NULL)
        {
            if(m.count(p)!=0)
            {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }
};
// @lc code=end

