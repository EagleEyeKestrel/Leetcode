//
//  main.cpp
//  比较简单，找到两个1/3 2/3的分界线，看看中间有几个0然后一乘就好了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numWays(string s) {
        int n = s.size(), mod = 1e9 + 7, cnt = 0;
        for (char c: s) if (c == '1') cnt++;
        if (cnt % 3) return 0;
        if (!cnt) return (long long)(n - 1) * (n - 2) / 2 % mod;
        int p1 = -1, p2 = -1, p3 = -1, p4 = -1, tmp = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') tmp++;
            if (tmp == cnt / 3 && p1 == -1) p1 = i;
            if (tmp == cnt / 3 + 1 && p2 == -1) p2 = i;
            if (tmp == cnt * 2 / 3 && p3 == -1) p3 = i;
            if (tmp == cnt * 2 / 3 + 1 && p4 == -1) p4 = i;
        }
        return (long long)(p2 - p1) * (p4 - p3) % mod;
    }
};
