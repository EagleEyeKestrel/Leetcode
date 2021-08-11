//
//  main.cpp
//  马拉车想到了，但是后面扫描线解法确实没想到
//  前面的马拉车解法不用插入特殊字符了。具体可以去看题解，讲的很详细
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    long long maxProduct(string s) {
        int n = s.size();
        int p[n + 1];
        s.insert(s.begin(), '\\');
        p[0] = 1;
        int mx = 0, id = 0;
        for (int i = 1; i <= n; i++) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (s[i + p[i]] == s[i - p[i]]) p[i]++;
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }
        int r[n + 1], l[n + 1];
        memset(r, 0, sizeof(r));
        memset(l, 0, sizeof(l));
        for (int i = 1; i <= n; i++) {
            r[i + p[i] - 1] = max(r[i + p[i] - 1], 2 * p[i] - 1);
        }
        for (int i = 2; i <= n; i++) r[i] = max(r[i], r[i - 1]);
        for (int i = n - 1; i >= 1; i--) {
            r[i] = max(r[i], r[i + 1] - 2);
        }
        for (int i = n; i >= 1; i--) {
            l[i - p[i] + 1] = max(l[i - p[i] + 1], 2 * p[i] - 1);
        }
        for (int i = n - 1; i >= 1; i--) l[i] = max(l[i], l[i + 1]);
        for (int i = 2; i <= n; i++) {
            l[i] = max(l[i], l[i - 1] - 2);
        }
        long long res = 1;
        for (int i = 1; i < n; i++) res = max(res, (long long)r[i] * l[i + 1]);
        return res;
    }
};
