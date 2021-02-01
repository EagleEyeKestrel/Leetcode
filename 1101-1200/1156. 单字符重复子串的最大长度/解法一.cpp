//
//  main.cpp
//  我的解法，比较烦
//  用l[i]表示text[i]以左连续的字符字数，并对所有字符计数
//  然后从右往左开始遍历。假如要更换text[i]
//  第一种情况，text[i]左右的元素相同，如果外面还有别的元素，那么换进来
//  第二种情况，text[i]左右的元素不同，那么就换成和左右某个一样
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size(), res = 0, tmp = 0;
        int cnt[128];
        memset(cnt, 0, sizeof(cnt));
        for (char c: text) cnt[c]++;
        int l[n + 1];
        l[0] = 0;
        for (int i = 0; i < n; i++) {
            if (!i || text[i] != text[i - 1]) tmp = 1;
            else tmp++;
            l[i + 1] = tmp;
            res = max(res, tmp);
        }
        if (l[n - 1] < cnt[text[n - 2]]) res = max(res, l[n - 1] + 1);
        tmp = 0;
        for (int i = n - 1; i > 0; i--) {
            if (i == n - 1 || text[i] != text[i + 1]) tmp = 1;
            else tmp++;
            if (i == 1) {
                if (tmp < cnt[text[1]]) res = max(res, tmp + 1);
                break;
            }
            if (text[i - 2] == text[i]) {
                if (cnt[text[i]] > tmp + l[i - 1]) res = max(res, tmp + l[i - 1] + 1);
                else res = max(res, tmp + l[i - 1]);
            } else {
                if (cnt[text[i]] > tmp) res = max(res, tmp + 1);
                if (cnt[text[i - 2]] > l[i - 1]) res = max(res, l[i - 1] + 1);
            }
        }
        return res;
    }
};
