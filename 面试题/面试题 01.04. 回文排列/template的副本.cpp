//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int cnt[128], res = 0;
        memset(cnt, 0, sizeof(cnt));
        for (char c: s) {
            cnt[c] = !cnt[c];
        }
        for (int num: cnt) res += num;
        return res <= 1;
    }
};
