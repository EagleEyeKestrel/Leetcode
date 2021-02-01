//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int cnt[100];
        memset(cnt, 0, sizeof(cnt));
        for (int i = lowLimit; i <= highLimit; i++) {
            int j = i, tmp = 0;
            while (j > 0) {
                tmp += j % 10;
                j /= 10;
            }
            cnt[tmp]++;
        }
        int res = 0;
        for (int i = 0; i < 100; i++) res = max(res, cnt[i]);
        return res;
    }
};
