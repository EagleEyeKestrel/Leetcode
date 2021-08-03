//
//  main.cpp
//  容易发现可以用差分来计算 每个点真实的颜色值
//  区间由于也是不超过1e5的，所以可以遍历区间解决
//  但由最后一个样例可以发现，对于两段区间，即使颜色的和相同，也要算做两对
//  所以就处理了一下所有的区间点。然后对每两个区间点之间 算一下最后的颜色
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        long long n = segments.size();
        long long a[100010];
        memset(a, 0, sizeof(a));
        vector<long long> v;
        for (auto &seg: segments) {
            a[seg[0]] += seg[2];
            a[seg[1]] -= seg[2];
            v.push_back(seg[0]);
            v.push_back(seg[1]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 1; i <= v.back(); i++) a[i] += a[i - 1];
        vector<vector<long long>> res;
        for (int i = 0; i < v.size() - 1; i++) {
            long long l = v[i], r = v[i + 1];
            if (a[l]) res.push_back({l, r, a[l]});
        }
        return res;
    }
};
