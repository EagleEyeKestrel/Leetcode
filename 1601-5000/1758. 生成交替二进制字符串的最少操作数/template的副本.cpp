//
//  main.cpp
//  结果要么是010101.. 要么是101010...
//  比较转化成两种的较小值
//  要注意，一个一个遍历贪心转化是错的，比如0010101，如果贪心，会变成0101010，显然不对
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), res1 = 0, res2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0' + (i & 1)) res1++;
            else res2++;
        }
        return min(res1, res2);
    }
};
