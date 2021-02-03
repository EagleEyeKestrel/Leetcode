//
//  main.cpp
//  滑动窗口的题目
//  朴素的解法是带注释部分的，但其实注释部分是不需要的
//  maxcnt可以变成历史上窗口中的最大计数，而非现在
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), l = 0, maxcnt = 0, res = 0;
        int cnt[26] = { 0 };
        for (int r = 0; r < n; r++) {
            cnt[s[r] - 'A']++;
            maxcnt = max(cnt[s[r] - 'A'], maxcnt);
            while (r - l + 1 > maxcnt + k) {
                cnt[s[l] - 'A']--;
                /*maxcnt = 0;
                for (int i = 0; i < 26; i++) maxcnt = max(maxcnt, cnt[i]);*/
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
