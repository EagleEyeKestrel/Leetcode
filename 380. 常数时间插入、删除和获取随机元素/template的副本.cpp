//
//  main.cpp
//  集合肯定要set，然后要随即返回就需要一个vector
//  关键是删除了一个vector中间位置的元素怎么办？
//  记录每个元素的索引，每次直接和末尾交换即可
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class RandomizedSet {
public:
    unordered_set<int> s;
    vector<int> v;
    unordered_map<int, int> m;
    int sz = 0;
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.count(val)) return false;
        s.insert(val);
        v.push_back(val);
        sz++;
        m[val] = sz - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!s.count(val)) return false;
        int index = m[val];
        if(index != sz - 1) {
            m[v.back()] = index;
            v[index] = v.back();
        }
        v.pop_back();
        sz--;
        m.erase(val);
        s.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % sz];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
