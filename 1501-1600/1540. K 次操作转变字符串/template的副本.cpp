//
//  main.cpp
//  容易错的是忘记讨论s的长度不等于t。。
//  然后就简单了，把转化的次数映射到Z26上，看k是不是比最大的一次转化还大
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                cnt[(t[i] - s[i] + 26) % 26]++;
            }
        }
        for (int i = 1; i <= 25; i++) {
            if (26 * (cnt[i] - 1) + i > k) return false;
        }
        return true;
    }
};
