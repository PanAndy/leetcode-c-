/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<map>
#include<list>
using namespace std;

struct Node{
    int key;
    int value;
    Node(int key, int value){
        this->key = key;
        this->value = value;
    } 
    Node(){

    }
};


class LRUCache {
public:
 
    int capacity;

    list<Node*> head;
    map<int, Node*> m;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        int value = -1;
        if(m.count(key))
        {
            value = m[key]->value;
            put(key, value);
        }
        return value;
    }
    
    void put(int key, int value) {
        Node *x = new Node(key, value);
        if(m.count(key))
        {
            //修改节点value
            //将节点提到head的位置            
            head.remove(m[key]);
            head.push_front(x);
            m[key] = x;
        }else{
            //新建一个节点
            //考虑capacity
            if(m.size()== capacity)
            {
                Node *last = head.back();
                m.erase(last->key); 
                head.pop_back();
            }
            head.push_front(x);
            m[key] = x;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

