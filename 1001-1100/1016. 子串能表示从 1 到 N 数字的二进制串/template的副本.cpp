//
//  main.cpp
// 看了评论区，N是10^9的范围，即使去除冗余的一半照理来说也超时吧？因为S的长度不超过1000，所以生成的不同子串的种类数不会超过1000^2，对于超过百万的情况特判一下
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int vis[1000010];
    bool queryString(string S, int N) {
        if (N >= 1e6) return false;
        memset(vis, 0, sizeof(vis));
        int n = S.size();
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = i; j < n; j++) {
                tmp = (tmp << 1) + S[j] - '0';
                if (tmp > 1e6) break;
                vis[tmp] = 1;
            }
        }
        for (int i = 1; i <= N; i++) {
            if (!vis[i]) return false;
        }
        return true;
    }
};
