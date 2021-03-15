//
//  main.cpp
//  数据范围小，暴力就能过。。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class MyHashSet {
public:
    /** Initialize your data structure here. */
    int vis[1000010];
    MyHashSet() {
        memset(vis, 0, sizeof(vis));
    }
    
    void add(int key) {
        vis[key] = 1;
    }
    
    void remove(int key) {
        vis[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return vis[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
