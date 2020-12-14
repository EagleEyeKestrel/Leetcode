//
//  main.cpp
//  一开始没仔细看数据范围，还以为是个简单的遍历题。。
//  所以就不可能把A变成实际的数组了，对A直接操作。now标记当前v有效位置的开始
//  Copyright © 2020 ji luyang. All rights reserved.
//

class RLEIterator {
public:
    vector<int> v;
    int now = 0;
    RLEIterator(vector<int>& A) {
        v = A;
    }
    
    int next(int n) {
        int res;
        for (int i = now; i < v.size() && n; i += 2) {
            if (n >= v[i]) {
                n -= v[i];
                res = v[i + 1];
                now += 2;
            } else {
                v[i] -= n;
                res = v[i + 1];
                break;
            }
        }
        if (now >= v.size() && n) return -1;
        return res;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
