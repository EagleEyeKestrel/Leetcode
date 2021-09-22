//
//  main.cpp
//  算到每个怪物的到达时间，排序，看哪个怪物处理不了了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        int t[n];
        for (int i = 0; i < n; i++) {
            if (dist[i] % speed[i] == 0) t[i] = dist[i] / speed[i];
            else t[i] = dist[i] / speed[i] + 1;
        }
        sort(t, t + n);
        for (int i = 0; i < n; i++) {
            if (t[i] <= i) return i;
        }
        return n;
    }
};
