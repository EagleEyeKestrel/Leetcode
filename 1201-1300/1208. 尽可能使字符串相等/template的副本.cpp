//
//  main.cpp
//  长度相等，每一位对应了一个cost，要找到最长的子串，使得cost不超过maxCost
//  其实就是滑动窗口问题
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), l = 0, tmp = 0, res = 0;
        int a[n];
        for (int i = 0; i < n; i++) {
            a[i] = abs(s[i] - t[i]);
        }
        for (int r = 0; r < n; r++) {
            tmp += a[r];
            while (l <= r && tmp > maxCost) {
                tmp -= a[l++];
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
