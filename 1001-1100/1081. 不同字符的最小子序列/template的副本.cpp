//
//  main.cpp
//  见316
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    string smallestSubsequence(string s) {
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
            while (!res.empty() && r[res.back() - 'a'] > i && res.back() > s[i]) {
                vis[res.back() - 'a'] = 0;
                res.pop_back();
            }
            res.push_back(s[i]);
            vis[s[i] - 'a'] = 1;
        }
        return res;
    }
};
