//
//  main.cpp
//  写了一段大概是只有我一个人才看得懂的代码，不过复杂度确实是O(mn)，和n1n2无关
//  思路大概是这样。首先n2可以不看，因为记s1*n1中出现了ans次s2，那么结果就是ans/n2
//  为了看s2 in s1*n1的次数，对s2在s1*n1中循环，记录每一次s2结束的时候在s1上的索引
//  比如 s1="baba" s2="baab"
//  baba baba baba baba baba baba
//  ba a b ba  ab  ba a b ba  ab
//  在s1中，第一次出现循环的结束点是在s1的16处
//  在一次循环中我们可以算出s1cycle(一次循环包括几个s1)，s1first(第一次循环末尾是第几个s1)
//  然后算出k，即第k段循环 不会超过n1个s1
//  最后特殊处理一下最后一段
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int l = 0, r = 0, m = s1.size(), n = s2.size(), round = 1;
        int flag[26] = { 0 };
        for (char c: s1) flag[c - 'a'] = 1;
        for (char c: s2) {
            if (flag[c - 'a'] == 0) return 0;
        }
        
        pair<int, int> vis[m];
        memset(vis, 0, sizeof(vis));
        int r1, r2, l1, l2;
        while (1) {
            r = 0;
            while (r < n) {
                while (s1[l % m] != s2[r]) l++;
                r++, l++;
            }
            if (vis[(l + m - 1) % m].second) {
                l1 = vis[(l + m - 1) % m].first, r1 = vis[(l + m - 1) % m].second;
                l2 = l - 1;
                r2 = round;
                break;
            } else {
                vis[(l + m - 1) % m].first = l - 1;
                vis[(l + m - 1) % m].second = round;
                round++;
            }
        }

        int s1cycle = (l2 - l1) / m, s1first = l1 / m + 1;
        int k = (n1 - s1first) / s1cycle + 1;
        if (s1first > n1) return 0;
        l = l1 + (k - 1) * (l2 - l1) + 1;
        int ans = (r2 - r1) * (k - 1) + r1;
        while (l < n1 * m) {
            r = 0;
            while (r < n) {
                while (s1[l % m] != s2[r]) l++;
                r++, l++;
            }
            if (l <= n1 * m) {
                ans++;
            } else {
                break;
            }
        }
        return ans / n2;

    }
};
