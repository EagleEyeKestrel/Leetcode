//
//  main.cpp
//  看上去数据很大，实际上直接模拟是不会超时的，顶多也就根号下2^31，也就是2的十几次方级别
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int now = 1;
        while (1) {
            if (memory1 >= memory2) {
                if (memory1 < now) {
                    return { now, memory1, memory2 };
                }
                memory1 -= now;
            } else {
                if (memory2 < now) {
                    return { now, memory1, memory2 };
                }
                memory2 -= now;
            }
            now++;
        }
        return {};
    }
};
