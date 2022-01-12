//
//  main.cpp
//  作为最后一题真不难。穷举先往左还是往右，然后折返。前缀和优化一下
//  注意边界情况的处理，12-14行。开始没注意导致WA
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int sum[200010], a[200010];
    int getsum(int l, int r) {
        if (l > r || r < 0) return 0;
        r = min(r, 200000);
        l = max(l, 0);
        return l == 0 ? sum[r] : sum[r] - sum[l - 1];
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        memset(a, 0, sizeof(a));
        for (auto &fruit: fruits) {
            a[fruit[0]] = fruit[1];
        }
        sum[0] = a[0];
        for (int i = 1; i <= 200000; i++) sum[i] = sum[i - 1] + a[i];
        int res = 0;
        for (int l = 0; l <= k && l <= startPos; l++) {
            int s1 = getsum(startPos - l, startPos);
            int r = max(0, k - l - l);
            int s2 = getsum(startPos + 1, startPos + r);
            res = max(res, s1 + s2);
        }
        for (int r = 0; r <= k && r + startPos <= 200000; r++) {
            int s1 = getsum(startPos, startPos + r);
            int l = max(0, k - r - r);
            int s2 = getsum(startPos - l, startPos - 1);
            res = max(res, s1 + s2);
        }
        return res;
    }
};
