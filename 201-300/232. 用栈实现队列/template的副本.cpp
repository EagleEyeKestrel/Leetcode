//
//  main.cpp
//  s2作为输出栈，s1作为输入栈。如果输出栈空了，那么把s1的元素再压到s2里
//  Copyright © 2021 ji luyang. All rights reserved.
//

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1, s2;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res;
        if (!s2.empty()) {
            res = s2.top();
            s2.pop();
        } else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            res = s2.top();
            s2.pop();
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        int res;
        if (!s2.empty()) res = s2.top();
        else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            res = s2.top();
        }
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
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
