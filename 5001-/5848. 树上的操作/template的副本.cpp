//
//  main.cpp
//  看上去很难，一看数据量只有2000，那直接朴素实现就可以了，唯一做的就是需要把父亲数组转变成儿子数组。另外用个mp表示节点是否上锁，以及是谁上锁的即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class LockingTree {
public:
    int mp[2048];
    vector<int> children[2048];
    vector<int> p;
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        this->p = parent;
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }
        memset(mp, 0, sizeof(mp));
    }
    
    bool lock(int num, int user) {
        if (mp[num]) return false;
        mp[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (mp[num] == 0 || mp[num] != user) return false;
        mp[num] = 0;
        return true;
    }

    void dfs(int num, vector<int> &locks) {
        if (mp[num]) locks.push_back(num);
        for (int v: children[num]) {
            dfs(v, locks);
        }
    }
    bool upgrade(int num, int user) {
        if (mp[num]) return false;
        int now = num;
        while (now != -1) {
            if (mp[now]) return false;
            now = p[now];
        }
        vector<int> locks;
        dfs(num, locks);
        if (locks.empty()) return false;
        for (int x: locks) mp[x] = 0;
        mp[num] = user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
