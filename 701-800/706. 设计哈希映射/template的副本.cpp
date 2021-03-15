//
//  main.cpp
//  数据量小。。暴力就能过，否则要用一些哈希方法
//  Copyright © 2021 ji luyang. All rights reserved.
//

class MyHashMap {
public:
    /** Initialize your data structure here. */
    int vis[1000010];
    MyHashMap() {
        for (int i = 1; i <= 1000000; i++) vis[i] = -1;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        vis[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return vis[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        vis[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
