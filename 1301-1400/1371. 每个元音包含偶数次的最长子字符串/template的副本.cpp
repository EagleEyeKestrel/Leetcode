//
//  main.cpp
//  第一眼像滑动窗口的题，但仔细想想发现并不满足滑动窗口的条件
//  其实对于aeiou的个数可以压缩进一个state，因为只需看奇偶即可
//  每次遍历到一个state，vis记录这个state最早出现的位置
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size(), state = 0, res = 0;
        int vis[100];
        for (int i = 0; i < 100; i++) vis[i] = INT_MAX;
        vis[0] = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') state ^= 1;
            if (s[i] == 'e') state ^= 2;
            if (s[i] == 'i') state ^= 4;
            if (s[i] == 'o') state ^= 8;
            if (s[i] == 'u') state ^= 16;
            if (vis[state] == INT_MAX) vis[state] = i;
            else res = max(res, i - vis[state]);
        }
        return res;
    }
};
