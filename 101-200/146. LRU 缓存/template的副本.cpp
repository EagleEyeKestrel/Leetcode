//
//  main.cpp
//  用list就可以模拟双向链表
//  node存一个key在链表里的位置
//  注意在达到cap时，删掉的key别忘了在对应数据结构中进行更新
//  Copyright © 2021 ji luyang. All rights reserved.
//

class LRUCache {
public:
    int cap;
    unordered_map<int, int> mp;
    list<int> l;
    unordered_map<int, list<int>::iterator> node;
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;
        int res = mp[key];
        l.erase(node[key]);
        l.push_front(key);
        node[key] = l.begin();
        return res;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            l.erase(node[key]);
        } else {
            if (l.size() == cap) {
                int out = l.back();
                mp.erase(out);
                l.pop_back();
                node.erase(out);
            }
        }
        mp[key] = value;
        l.push_front(key);
        node[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */