//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int totalMoney(int n) {
        int tmp = 1, res = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 7 == 1) {
                tmp = i / 7 + 1;
            } else {
                tmp++;
            }
            res += tmp;
        }
        return res;
    }
};
