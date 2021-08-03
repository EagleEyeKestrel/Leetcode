//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (char c: s) {
            cnt[c - 'a']++;
        }
        int v = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) {
                if (v == -1) v = cnt[i];
                else if (cnt[i] != v) return false;
            }
        }
        return true;
    }
};
