//
//  main.cpp
//  做过，还是没能想到栈的解法。。
//  一个字母弹出之前的一个字母，肯定是当前的字母更小，而且弹出的字母后面还有，所以能形成更小的字符串
//  另外，如果之前的字符串里已经有了这个字母，应该直接跳过，因为用当前字母形成的字符串，之前那个，肯定也能组成
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int r[26], vis[26];
        memset(vis, 0, sizeof(vis));
        int n = s.size();
        for (int i = 0; i < 26; i++) r[i] = -1;
        string res;
        for (int i = 0; i < n; i++) {
            r[s[i] - 'a'] = max(r[s[i] - 'a'], i);
        }
        for (int i = 0; i < n; i++) {
            if (vis[s[i] - 'a']) continue;
            while (!res.empty() && r[res.back() - 'a'] >= i && res.back() >= s[i]) {
                vis[res.back() - 'a'] = 0;
                res.pop_back();
            }
            res.push_back(s[i]);
            vis[s[i] - 'a'] = 1;
        }
        return res;
    }
};
