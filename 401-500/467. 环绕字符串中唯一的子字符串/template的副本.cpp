//
//  main.cpp
//  不难，cnt记录每个字母之前最长的连续串长度
//  比如有"zab"，那么cnt[1]就等于3。 最后对26个字母累加即可
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int res = 0, now = 1;
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        if(p == "") return 0;
        cnt[p[0] - 'a'] = 1;
        for(int i = 1; i < p.size(); i++) {
            if(p[i] == p[i - 1] + 1 || p[i] == 'a' && p[i - 1] == 'z') {
                now++;
            } else {
                now = 1;
            }
            cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], now);
        }
        for(int i = 0; i < 26; i++) res += cnt[i];
        return res;
    }
};
