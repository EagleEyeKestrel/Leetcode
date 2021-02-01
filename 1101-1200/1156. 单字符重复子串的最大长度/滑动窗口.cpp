//
//  main.cpp
//  滑动窗口法，维护一个最多只有一个其他字符的窗口
//  要么kinds==1，要么kinds==2并且最少的字符只有一个
//  对于这个窗口，如果只有一种字符，那就是这个窗口的长度
//  如果有两种，如果长度为二，就是ab这样，那么如果有哪个还有其他字符，那res可以达到2
//  如果长度大于2，那么就找数量大于1的字母，看看有没有其他字符可以用来替换了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size(), res = 1, l = 0, kinds = 0;
        int cnt[26], tmp[26];
        memset(cnt, 0, sizeof(cnt));
        memset(tmp, 0, sizeof(tmp));
        for (char c: text) cnt[c - 'a']++;
        for (int r = 0; r < n; r++) {
            tmp[text[r] - 'a']++;
            if (tmp[text[r] - 'a'] == 1) kinds++;
            while (1) {
                int minv = INT_MAX;
                for (int j = 0; j < 26; j++) {
                    if (tmp[j]) minv = min(minv ,tmp[j]);
                }
                if (kinds == 1 || kinds == 2 && minv == 1) break;
                tmp[text[l] - 'a']--;
                if (tmp[text[l] - 'a'] == 0) kinds--;
                l++;
            }
            if (kinds == 1) res = max(res, r - l + 1);
            else {
                if (r == l + 1) {
                    if (cnt[text[l] - 'a'] > 1 || cnt[text[r] - 'a'] > 1) {
                        res = max(res, 2);
                    }
                } else {
                    for (int j = 0; j < 26; j++) {
                        if (tmp[j] > 1 && cnt[j] > tmp[j]) {
                            res = max(res, r - l + 1);
                        }
                    }
                }
            }
        }
        return res;
    }
};
