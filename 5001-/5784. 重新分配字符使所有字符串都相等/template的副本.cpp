//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int vis[26];
        memset(vis, 0, sizeof(vis));
        for (auto &word: words) {
            for (char c: word) {
                vis[c - 'a']++;
            }
        }
        int n = words.size();
        for (int i = 0; i < 26; i++) {
            if (vis[i] % n) return false;
        }
        return true;
    }
};
