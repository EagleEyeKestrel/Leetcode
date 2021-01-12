//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (char c: s) cnt[c - 'a']++;
        for (char c: t) cnt[c - 'a']--;
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) res += cnt[i];
        }
        return res;
    }
};
