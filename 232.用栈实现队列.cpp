/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start

#include<iostream>
#include<stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s;
    stack<int> s_tmp;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!s.empty()){
            s_tmp.push(s.top());
            s.pop();
        }
        s_tmp.push(x);
        while(!s_tmp.empty()){
            s.push(s_tmp.top());
            s_tmp.pop();
        }        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int front = s.top();
        s.pop();
        return front;
    }
    
    /** Get the front element. */
    int peek() {
        return s.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

