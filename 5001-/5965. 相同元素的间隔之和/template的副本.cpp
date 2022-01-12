//
//  main.cpp
//  维护一个数字的位置索引列表
//  然后就维护一个前缀和一个后缀和，计算差值的和
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<int> pos[100010];
        for (int i = 0; i < n; i++) pos[arr[i]].push_back(i);
        vector<long long> res(n);
        for (int i = 1; i <= 100000; i++) {
            vector<int> &v = pos[i];
            long long pre = 0, suf = 0;
            for (int x: v) suf += x;
            long long sufnum = v.size() - 1;
            for (int j = 0; j < v.size(); j++) {
                int id = v[j];
                suf -= v[j];
                res[id] = suf - sufnum * id + (v.size() - sufnum - 1) * id - pre;
                pre += v[j];
                sufnum--;
            }
        }
        return res;
    }
};
