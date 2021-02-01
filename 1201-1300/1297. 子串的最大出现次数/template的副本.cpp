//
//  main.cpp
//  直接穷举minsize - maxsize的所有子串是可以过的，要用unordered_map，用map就超时
//  实际上有更好的做法。因为，更长的一个子串出现了若干次，那么一定意味着一个小的子串也出现了若干次
//  只要算最大出现次数的话，只需要看minSize即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size(), res = 0;
        unordered_map<string, int> mp;
        for (int l = minSize; l <= minSize; l++) {
            int letters = 0;
            int cnt[128];
            memset(cnt, 0, sizeof(cnt));
            for (int r = 0; r < n; r++) {
                cnt[s[r]]++;
                if (cnt[s[r]] == 1) letters++;
                if (r >= l) {
                    cnt[s[r - l]]--;
                    if (cnt[s[r - l]] == 0) letters--;
                }
                if (letters <= maxLetters && r >= l - 1) {
                    mp[s.substr(r - l + 1, l)]++;
                }
            }
        }
        for (auto it: mp) res = max(res, it.second);
        return res;
    }
};
