//
//  main.cpp
//  每个数都不会增加太多，暴力就行了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(int x) {
        string s = to_string(x);
        int cnt[10] = {0};
        for (char c: s) {
            cnt[c - '0']++;
        }
        for (int i = 0; i < 10; i++) {
            if (cnt[i] > 0 && cnt[i] != i) {
                return 0;
            }
        }
        return 1;
    }
    int nextBeautifulNumber(int n) {
        for (int i = n + 1; ; i++) {
            if (f(i)) return i;
        }
        return -1;
    }
};
