//
//  main.cpp
//  后来看大佬们直接调stl就能过了，想想也是，顶多O(n2)
//  这里是个O(1)解法，维护两个大小之差不超过1的deque
//  由于题目的特性，当有两个优先取前者，所以设计b.size()可以是a.size() || a.size() + 1
//  这样处理middle更方便一点。当然也可以a.size()更大，略烦一点点
//  Copyright © 2020 ji luyang. All rights reserved.
//

class FrontMiddleBackQueue {
public:
    deque<int> a, b;
    FrontMiddleBackQueue() {

    }
    
    void pushFront(int val) {
        a.push_front(val);
        if(a.size() > b.size()) {
            int v = a.back();
            a.pop_back();
            b.push_front(v);
        }
    }
    
    void pushMiddle(int val) {
        if(a.size() == b.size()) {
            b.push_front(val);
        } else {
            a.push_back(val);
        }
    }
    
    void pushBack(int val) {
        b.push_back(val);
        if(b.size() > a.size() + 1) {
            int v = b.front();
            b.pop_front();
            a.push_back(v);
        }
    }
    
    int popFront() {
        if(b.empty()) return -1;
        int res;
        if(a.empty()) {
            res = b.front();
            b.pop_front();
        } else {
            res = a.front();
            a.pop_front();
            if(a.size() < b.size() - 1) {
                int v = b.front();
                b.pop_front();
                a.push_back(v);
            }
        }
        return res;
    }
    
    int popMiddle() {
        if(b.empty()) return -1;
        int res;
        if(a.size() == b.size()) {
            res = a.back();
            a.pop_back();
        } else {
            res = b.front();
            b.pop_front();
        }
        return res;
    }
    
    int popBack() {
        if(b.empty()) return -1;
        int res = b.back();
        b.pop_back();
        if(b.size() < a.size()) {
            int v = a.back();
            a.pop_back();
            b.push_front(v);
        }
        return res;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
