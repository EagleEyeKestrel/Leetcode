//
//  main.cpp
//  既然是s1的排列，说明只需要有一个和s1等长的子串，字符恰好和s1完全相同
//  检查所有的[r-m+1, r]区间，检查是否所有字符数恰好相等。复杂度O(m+26n)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int cnt[128] = { 0 };
        int m = s1.size(), n = s2.size();
        if (n < m) return false;
        for (char c: s1) cnt[c]++;
        for (int r = 0; r < n; r++) {
            cnt[s2[r]]--;
            if (r >= m) cnt[s2[r - m]]++;
            if (r >= m - 1) {
                int flag = 1;
                for (int i = 'a'; i <= 'z'; i++) {
                    if (cnt[i]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) return true;
            }
        }
        return false;
    }
};
