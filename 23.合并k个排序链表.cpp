/*
@lc app=leetcode.cn id=23 lang=cpp
 *
[23] 合并K个排序链表
 */

// @lc code=start
/**
Definition for singly-linked list. */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // auto cmp = [](ListNode* &left, ListNode* &right){
        //     return left->val > right->val;
        // };
        // priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q;

        struct node{
            ListNode* p=NULL;
            int val;
            node(){

            }
            node(ListNode* p, int val):p(p), val(val){}
            bool operator > (const node &r) const{
                return p->val > r.val;
            }
        };
        priority_queue<node, vector<node>, greater<node>> q;
        int n = lists.size();
        if(n==0)return NULL;
        for(int i=0;i<n;i++)
        {
            if(lists[i])
                q.emplace(lists[i], lists[i]->val);
        }
        // ListNode* head = q.top().p;
        // ListNode* p = head;

        ListNode head(0), *p = &head;
        while(!q.empty())
        {
            auto top = q.top();
            q.pop();
            p->next = top.p;
            p = p->next;
            if(top.p->next!=NULL)
                q.emplace(top.p->next, top.p->next->val);
        }
        p->next = NULL;
        return head.next;
    }
};
// @lc code=end

