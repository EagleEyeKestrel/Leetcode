//
//  main.cpp
//  后缀数组模版题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int wa[400010], wb[400010], wv[400010], Ws[400010];
    int sa[400010];
    void buildSA(string &s, int n, int m) {
        int i, j, p, *pm = wa, *k2sa = wb, *t;
        for (i = 0; i <= m; i++) Ws[i] = 0;
        for (i = 1; i <= n; i++) Ws[pm[i] = s[i]]++;
        for (i = 1; i <= m; i++) Ws[i] += Ws[i - 1];
        for (i = n; i >= 1; i--) sa[Ws[pm[i]]--] = i;
        for (j = p = 1; p < n; j <<= 1, m = p) {
            for (p = 0, i = n - j + 1; i <= n; i++) k2sa[++p] = i;
            for (i = 1; i <= n; i++) if (sa[i] > j) k2sa[++p] = sa[i] - j;
            for (i = 0; i <= m; i++) Ws[i] = 0;
            for (i = 1; i <= n; i++) Ws[wv[i] = pm[k2sa[i]]]++;
            for (i = 1; i <= m; i++) Ws[i] += Ws[i - 1];
            for (i = n; i >= 1; i--) sa[Ws[wv[i]]--] = k2sa[i];
            for (t = pm, pm = k2sa, k2sa = t, pm[sa[1]] = 1, p = 1, i = 2; i<=n; i++) {
                int a = sa[i - 1], b = sa[i];
                if (k2sa[a] == k2sa[b] && k2sa[a + j] == k2sa[b + j])
                    pm[sa[i]] = p;
                else
                    pm[sa[i]] = ++p;
            }
        }
    }
    string lastSubstring(string s) {
        int n = s.size(), m = 128;
        s.insert(s.begin(), ' ');
        buildSA(s, n, m);
        return s.substr(sa[s.size() - 1]);
    }
};
