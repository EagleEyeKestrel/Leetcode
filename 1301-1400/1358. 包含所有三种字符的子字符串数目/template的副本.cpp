//
//  main.cpp
//  简单的滑动窗口，对于一个r，可以找到l的最右边界，此时l可以取0到这个边界。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), res = 0, l = 0;
        int sum[3] = { 0 };
        for (int r = 0; r < n; r++) {
            sum[s[r] - 'a']++;
            if (!sum[0] || !sum[1] || !sum[2]) continue;
            while (sum[s[l] - 'a'] > 1) {
                sum[s[l++] - 'a']--;
            }
            res += l + 1;
        }
        return res;
    }
};
