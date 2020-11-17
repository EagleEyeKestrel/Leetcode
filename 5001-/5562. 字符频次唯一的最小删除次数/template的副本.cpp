//
//  main.cpp
//  统计次数，然后可以从大往小删除，删到上一个-1为止
//  WA了一次。。忽略了while cnt[i] &&... 当删到一个字母已经没有了就已经可以了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minDeletions(string s) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for(char c: s) {
            cnt[c - 'a']++;
        }
        sort(cnt, cnt + 26);
        int res = 0;
        for(int i = 24; i >= 0 && cnt[i]; i--) {
            while(cnt[i] && cnt[i] >= cnt[i + 1] ) {
                cnt[i]--;
                res++;
            }
        }
        return res;
    }
};
