//
//  main.cpp
//  统计每个数的出现次数，看最大公约数是否>=2
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        int n = deck.size(), res = -1;
        int cnt[10010];
        memset(cnt, 0, sizeof(cnt));
        for (int x: deck) cnt[x]++;
        for (int i = 0; i < 10000; i++) {
            if (cnt[i]) {
                if (res == -1) res = cnt[i];
                else {
                    res = gcd(res, cnt[i]);
                }
            }
        }
        return res >= 2;
    }
};
