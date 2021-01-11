//
//  main.cpp
//  依稀记得这是最开始参加某个周赛的第三题？当时毫无思路
//  t[i]维护index=i处每次修改的时间，v[i]是值
//  每次查找，只要找到时间<= snap_id的最后一次修改即可。
//  注意k<0对应初始情况，返回0
//  Copyright © 2021 ji luyang. All rights reserved.
//

class SnapshotArray {
public:
    vector<int> t[50010], v[50010];
    int id;
    SnapshotArray(int length) {
        id = 0;
    }
    
    void set(int index, int val) {
        t[index].push_back(id);
        v[index].push_back(val);
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        int k = upper_bound(t[index].begin(), t[index].end(), snap_id) - t[index].begin() - 1;
        if (k < 0) return 0;
        return v[index][k];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
