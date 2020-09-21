//
//  main.cpp
//  既然允许重复，那用个set存储位置即可。
//  在remove的逻辑里面容易写得复杂。其实如果index和back重复，只要先erase再insert就不会出问题
//  开始数据结构里还有个set, 其实set的功能完全由map替代就可以了
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class RandomizedCollection {
public:
    vector<int> v;
    unordered_map<int, unordered_set<int>> m;
    int sz = 0;
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = true;
        if(!m[val].empty()) res = false;
        v.push_back(val);
        sz++;
        m[val].insert(sz - 1);
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m[val].empty()) return false;
        int index = *(m[val].begin());
        m[val].erase(index);
        if(index != sz - 1) {
            v[index] = v[sz - 1];
            m[v[sz - 1]].erase(sz - 1);
            m[v[sz - 1]].insert(index);
        }
        v.pop_back();
        sz--;
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand() % sz];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
