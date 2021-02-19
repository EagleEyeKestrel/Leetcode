//
//  main.cpp
//  本来想二分的，后来发现滑动窗口更好
//  一个区间[l,r]能替换的条件是，区间以外部分每个字母的数量都<= n/4
//  也就是while里面的条件。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int balancedString(string s) {
        int total[4] = { 0 }, cnt[4] = { 0 };
        string dict = "QWER";
        for (char c: s) {
            total[dict.find(c)]++;
        }
        int n = s.size(), res = n, l = 0;
        for (int r = 0; r < n; r++) {
            cnt[dict.find(s[r])]++;
            while (total[0] - cnt[0] <= n / 4 && total[1] - cnt[1] <= n / 4 && total[2] - cnt[2] <= n / 4 && total[3] - cnt[3] <= n / 4) {
                cnt[dict.find(s[l])]--;
                res = min(res, r - l + 1);
                if (res == 0) return res;
                l++;
            }
        }
        return res;
    }
};
