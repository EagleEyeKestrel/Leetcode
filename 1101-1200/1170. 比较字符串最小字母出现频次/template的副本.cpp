//
//  main.cpp
//  统计出fwords然后二分查找。20ms，看着一年前写的1800ms的算法陷入沉思。。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(string& s) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for(char c: s) {
            cnt[c - 'a']++;
        }
        for(int i = 0 ;i < 26; i++) {
            if(cnt[i]) return cnt[i];
        }
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int m = queries.size(), n = words.size();
        int fwords[n];
        for(int i = 0; i < n; i++) fwords[i] = f(words[i]);
        sort(fwords, fwords + n);
        vector<int> res;
        for(int i = 0; i < m; i++) {
            int fq = f(queries[i]);
            int tmp = upper_bound(fwords, fwords + n, fq) - fwords;
            res.push_back(n - tmp);
        }
        return res;
    }
};
