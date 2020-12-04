//
//  main.cpp
//  写了个线性筛，结果好像比普通筛法还慢？似乎快不了多少。
//  但要常看，不能忘了怎么筛，才能够每个元素只筛一次
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int isprime[5000010], res[5000010];
    int now = 0;
    void build(int n) {
        memset(isprime, 1, sizeof(isprime));
        isprime[1] = 0;
        for(int i = 2; i < n; i++) {
            if(isprime[i]) {
                res[now++] = i;
            }
            for(int j = 0; j <= now && res[j] * i < n; j++) {
                isprime[res[j] * i] = 0;
                if(i % res[j] == 0) break;
            }
        }
    }
    int countPrimes(int n) {
        build(n);
        return now;
    }
};
