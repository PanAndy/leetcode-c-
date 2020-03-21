/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */

// @lc code=start
// Definition for singly-linked list.

#include<iostream>
#include<vector>

using namespace std;

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ans=new ListNode(0);
        ListNode *q = ans;
        ListNode *p=head;
        int flag=0;
        while(p!=NULL)
        {
            if(p->next!=NULL){
                if(p->val == p->next->val)
                {
                    p = p->next;
                    flag = 1;
                }else{
                    if(flag == 0){
                        q->next = new ListNode(p->val);
                        q = q->next;;                    
                    }
                    p = p->next;
                    flag = 0;
                    }
            }else{
                if(flag==0)
                {
                    q->next = new ListNode(p->val);
                    q = q->next;
                }
                p = p->next;
            }      
        }
        return ans->next;
    }
};
// @lc code=end
