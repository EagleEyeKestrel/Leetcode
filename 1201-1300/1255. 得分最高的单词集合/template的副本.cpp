//
//  main.cpp
//  不是很明白为什么是困难？
//  因为words的长度很小，所以可以直接穷举所有拼接的子集，判断是否可行，更新最大分数
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size(), res = 0;
        int cnt[26], add[n];
        memset(cnt, 0, sizeof(cnt));
        memset(add, 0, sizeof(add));
        for (char c: letters) cnt[c - 'a']++;
        for (int i = 0; i < n; i++) {
            for (char c: words[i]) add[i] += score[c - 'a'];
        }
        for (int mask = 0; mask < (1 << n); mask++) {
            int tmp[26] = {0};
            int tmpScore = 0;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    for (char c: words[i]) tmp[c - 'a']++;
                    tmpScore += add[i];
                }
            }
            int flag = 1;
            for (int k = 0; k < 26; k++) {
                if (tmp[k] > cnt[k]) {
                    flag = 0;
                    break;
                }
            }
            if (!flag) continue;
            res = max(res, tmpScore);
        }
        return res;
    }
};
