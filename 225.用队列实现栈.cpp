/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start

#include<iostream>
#include<queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> q_tmp;
        while(q.size()>1){
            q_tmp.push(q.front());
            q.pop();
        }
        int top = q.front();
        q = q_tmp;
        return top;
    }
    
    /** Get the top element. */
    int top() {
        queue<int> q_tmp;
        while(q.size()>1){
            q_tmp.push(q.front());
            q.pop();
        }
        int top = q.front();
        q = q_tmp;
        q.push(top);
        return top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

