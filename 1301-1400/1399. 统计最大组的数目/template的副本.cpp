//
//  main.cpp
//  算出五个位，然后统计
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int countLargestGroup(int n) {
        int cnt[40];
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; i++) {
            int a = i % 10;
            int b = i / 10000;
            int c = (i - 10000 * b) / 1000;
            int d = (i - 10000 * b - 1000 * c) / 100;
            int e = (i % 100 - a) / 10;
            cnt[a + b + c + d + e]++;
        }
        int maxv = 0, res = 0;
        for(int i = 1; i < 40; i++) {
            if(cnt[i] == maxv) {
                res++;
            } else if(cnt[i] > maxv) {
                maxv = cnt[i];
                res = 1;
            }
        }
        return res;
    }
};
