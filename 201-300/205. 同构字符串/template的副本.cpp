//
//  main.cpp
//  m表示s[i]对应到什么，vis表示t中某个字母是不是已经被映射
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m[256], vis[256];
        memset(m, 0, sizeof(m));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (!m[c]) {
                if (vis[t[i]]) return false;
                m[c] = t[i];
                vis[t[i]] = 1;
            } else if (m[c] != t[i]) return false;
        }
        return true;
    }
};
