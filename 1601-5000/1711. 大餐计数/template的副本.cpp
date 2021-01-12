//
//  main.cpp
//  两两穷举和，看和是不是2的幂，肯定会超时。
//  想到2的幂很少，所以对每个元素x，看2的幂 - x有多少个就可以了。
//  为了防止重复，我原来喜欢先全部统计一遍deliciousness的元素的出现次数
//  现在发现边统计边计的写法，更简洁，m里的就是之前出现过的元素
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int m[1048577];
    int countPairs(vector<int>& deliciousness) {
        long mod = 1e9 + 7, res = 0;
        int twos[25];
        twos[0] = 1;
        for (int i = 1; i < 25; i++) {
            twos[i] = twos[i - 1] << 1;
        }
        memset(m, 0, sizeof(m));
        int n = deliciousness.size();
        for (int i = 0; i < n; i++) {
            int x = deliciousness[i];
            for (int j = 0; j < 25; j++) {
                int y = twos[j] - x;
                if (y >= 0 && y <= (1 << 20)) res = (res + m[y]) % mod;
            }
            m[x]++;
        }
        return res;
    }
};
