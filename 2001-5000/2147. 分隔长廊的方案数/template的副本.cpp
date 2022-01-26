//
//  main.cpp
//  ???这是困难？还周赛最后一题？虽然忘记判断cnt==0 WA了一次
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int pos[100010];
    int numberOfWays(string corridor) {
        int cnt = 0;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                pos[++cnt] = i;
            }
        }
        if (cnt == 0 || cnt & 1) return 0;
        long long res = 1;
        for (int i = 2; i <= cnt - 2; i += 2) {
            int l = pos[i], r = pos[i + 1];
            res = res * (r - l) % mod;
        }
        return res;
    }
};