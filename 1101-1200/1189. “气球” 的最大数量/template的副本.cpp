//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[128];
        memset(cnt, 0, sizeof(cnt));
        for (char c: text) cnt[c]++;
        int res = min(cnt['b'], cnt['a']);
        res = min(res, cnt['n']);
        res = min(res, min(cnt['l'] / 2, cnt['o'] / 2));
        return res;
    }
};
