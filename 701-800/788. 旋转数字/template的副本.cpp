//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f[10] = { 0, 1, 5, -1, -1, 2, 9, -1, 8, 6 };
    int rotatedDigits(int N) {
        int res = 0;
        for (int i = 1; i <= N; i++) {
            string si = to_string(i);
            int flag1 = 1, flag2 = 0;
            for (char c: si) {
                if (f[c - '0'] == -1) {
                    flag1 = 0;
                    break;
                }
                if (f[c - '0'] != c - '0') {
                    flag2 = 1;
                }
            }
            if (flag1 && flag2) res++;
        }
        return res;
    }
};
