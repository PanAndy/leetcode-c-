/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
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
#include<algorithm>
#include<ctime>
#include<cstdio>

using namespace std;

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    
    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
        srand(time(NULL));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int i = 0;
        int res = 0;
        ListNode* p = head;
        while(p!=NULL){
            rand()
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

