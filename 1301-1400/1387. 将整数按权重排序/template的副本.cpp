//
//  main.cpp
//  就模拟计算过程，加一个记忆化即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int cache[1000010];
    int search(int i) {
        if (cache[i] != -1) return cache[i];
        if (i % 2) cache[i] = 1 + search(3 * i + 1);
        else cache[i] = 1 + search(i >> 1);
        return cache[i];
    }
    int getKth(int lo, int hi, int k) {
        for (int i = 1; i < 1000010; i++) cache[i] = -1;
        cache[1] = 0;
        for (int i = lo; i <= hi; i++) {
            if (cache[i] == -1) {
                cache[i] = search(i);
            }
        }
        vector<int> v;
        for (int i = lo; i <= hi; i++) v.push_back(i);
        sort(v.begin(), v.end(), [&](int a, int b) {
            if (cache[a] == cache[b]) return a < b;
            return cache[a] < cache[b];
        });
        return v[k - 1];
    }
};
