//
//  main.cpp
//  直觉上对每个box列表，用package一个个去搜，但这样的复杂度是O(nlog(m1m2...mk))，其中mi是boxes[i]的长度。这种应该会超时
//  所以反过来实现，因为packages是固定的，我们对boxes[i]，看boxes[i][j]能一直装得下装到哪个package
//  二分查找到某个位置，然后预处理前缀和来计算结果。注意overflow
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int n = packages.size(), m = boxes.size();
        long long res = 1e18;
        long long sum[n];
        sort(packages.begin(), packages.end());
        for (auto &box: boxes) sort(box.begin(), box.end());
        for (int i = 0; i < n; i++) sum[i] = packages[i] + (i ? sum[i - 1] : 0);
        for (int i = 0; i < m; i++) {
            if (packages.back() > boxes[i].back()) continue;
            long long tmp = 0, last = -1;
            for (int j = 0; j < boxes[i].size(); j++) {
                auto it = upper_bound(packages.begin(), packages.end(), boxes[i][j]);
                long long id = it - packages.begin();
                tmp += boxes[i][j] * (id - last - 1) - (id ? sum[id - 1] : 0) + (last < 0 ? 0 : sum[last]);
                last = id - 1;
            }
            res = min(res, tmp);
        }
        return res == 1e18 ? -1 : res % mod;
    }
};
