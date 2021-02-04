//
//  main.cpp
//  滑动窗口题，不难
//  用cnt记录t中的所有字符，在s中碰到一个就cnt--
//  当cnt减了之后还大于等于0，说明这个字符是t里的。
//  当kinds计数是t的大小的时候说明这个时候已经包括了所有字符，进行minl的更新
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), l = 0, kinds = 0, minl = INT_MAX, minid = -1;
        int cnt[128] = { 0 };
        for (char c: t) cnt[c]++;
        for (int r = 0; r < n; r++) {
            --cnt[s[r]];
            if (cnt[s[r]] >= 0) kinds++;
            while (kinds == t.size()) {
                if (r - l + 1 < minl) {
                    minl = r - l + 1;
                    minid = l;
                }
                cnt[s[l]]++;
                if (cnt[s[l]] > 0) kinds--;
                l++;
            }
        }
        return minid == -1 ? "" : s.substr(minid, minl);
    }
};
