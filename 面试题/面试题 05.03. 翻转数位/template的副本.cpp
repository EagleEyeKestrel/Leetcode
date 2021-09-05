//
//  main.cpp
//  比较简单的题，但我们要争取做到O(1)空间
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int reverseBits(int num) {
        int res = 0, pre = 0, now = 0;
        for (int i = 0; i < 32; i++) {
            if ((num >> i & 1) == 0) {
                pre = now + 1;
                now = 0;
            } else {
                now++;
            }
            res = max(res, now + pre);
        }
        return res;
    }
};
