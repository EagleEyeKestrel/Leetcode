//
//  main.cpp
//  Leetcode滑动窗口第一题。
//  为什么只需要看cnt[s[r]]？因为r增加1格，只有可能cnt[s[r]]>1，其他一定都是<=1的(之前处理过)
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, l = 0;
        int cnt[128];
        memset(cnt, 0, sizeof(cnt));
        for(int r = 0; r < s.size(); r++) {
            cnt[s[r]]++;
            while(cnt[s[r]] > 1) {
                cnt[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
