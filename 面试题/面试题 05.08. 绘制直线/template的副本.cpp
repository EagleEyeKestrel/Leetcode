//
//  main.cpp
//  题目的描述也太垃圾了，不值得做。。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> res(length, 0);
        for(int i = x1; i <= x2; i++) {
            res[i / 32 + w / 32 * y] |= (1 << (31 - i % 32));
        }
        return res;
    }
};
