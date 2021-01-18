//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[128];
        memset(cnt, 0, sizeof(cnt));
        for (char c: magazine) cnt[c]++;
        for (char c: ransomNote) {
            cnt[c]--;
            if (cnt[c] < 0) return false;
        }
        return true;
    }
};
