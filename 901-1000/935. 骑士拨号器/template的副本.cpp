//
//  main.cpp
//  这道题我的评论在Leetcode里是置顶的，非常巧妙的做法
//  用a表示状态{1,3,7,9}, b = {4, 6}, c = {2, 8}, d = {0}（5只有第一步才有）
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int knightDialer(int N) {
        if(N == 1) return 10;
        int mod = 1e9 + 7;
        long a = 4, b = 2, c = 2, d = 1;
        for(int i = 1; i < N; i++) {
            long newa = (2 * b + 2 * c) % mod;
            long newb = (2 * d + a) % mod;
            c = a;
            d = b;
            a = newa;
            b = newb;
        }
        return (a + b + c + d) % mod;
    }
};
