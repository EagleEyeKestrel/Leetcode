//
//  main.cpp
//  r[i]表示某个字符及右边的字符种类数
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numSplits(string s) {
        int n = s.size(), res = 0, tmp = 0;
        int r[n], cnt[128];
        memset(cnt, 0, sizeof(cnt));
        for (int i = n - 1; i >= 0; i--) {
            if (!cnt[s[i]]) {
                cnt[s[i]] = 1;
                tmp++;
            }
            r[i] = tmp;
        }
        memset(cnt, 0, sizeof(cnt));
        tmp = 0;
        for (int i = 0; i < n - 1; i++) {
            if (!cnt[s[i]]) {
                cnt[s[i]] = 1;
                tmp++;
            }
            if (tmp == r[i + 1]) res++;
        }
        return res;
    }
};
