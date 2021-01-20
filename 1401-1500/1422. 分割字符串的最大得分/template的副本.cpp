//
//  main.cpp
//  cnt是1的前缀和
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), res = 0;
        int cnt[n + 1];
        cnt[0] = 0;
        for (int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + (s[i - 1] - '0');
        for (int i = 1; i < n; i++) {
            res = max(res, i - cnt[i] + cnt[n] - cnt[i]);
        }
        return res;
    }
};
