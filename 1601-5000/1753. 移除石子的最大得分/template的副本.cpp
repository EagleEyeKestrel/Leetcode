//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int res = 0;
        int tmp[3] = { a, b, c };
        while (1) {
            if ((tmp[0] == 0) + (tmp[1] == 0) + (tmp[2] == 0) >= 2) break;
            sort(tmp, tmp + 3);
            tmp[1]--;
            tmp[2]--;
            res++;
        }
        return res;
    }
};
