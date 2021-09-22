//
//  main.cpp
//  没什么技术含量的题。。。读k的范围可以发现，重复的序列长度不超过7
//  那么就是如何穷举这个序列。显然每个元素的总次数都得超过k，那至多也只有7个字母
//  用res[len]表示长度为len的所有子序列，依次往后递推，具体的复杂度证明不太会，但可以发现，肯定不会超过(7! * n)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    char c[10];
    int sz = 0;
    int f(string &t, string &s, int k) {
        int m = t.size(), n = s.size(), id = 0;
        int i = 0, j = 0;
        while (j < n) {
            if (s[j] == t[i]) {
                id++;
                i = (i + 1) % m;
            }
            j++;
        }
        return id / m >= k;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        vector<string> res[8];
        res[0].push_back("");
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (char c: s) cnt[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] >= k) {
                c[sz++] = i + 'a';
            }
        }
        for (int len = 0; len < 7; len++) {
            for (string &t: res[len]) {
                for (int i = 0; i < sz; i++) {
                    t.push_back(c[i]);
                    if (f(t, s, k)) res[len + 1].push_back(t);
                    t.pop_back();
                }
            }
        }
        for (int len = 1; len < 8; len++) {
            sort(res[len].begin(), res[len].end());
        }
        for (int len = 7; len >= 1; len--) {
            if (!res[len].empty()) return res[len].back();
        }
        return "";
    }
};
