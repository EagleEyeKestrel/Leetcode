//
//  main.cpp
//  这里直接模拟了，没有仔细想
//  其实只用考虑起始元素以及最后一个元素
//  一种取首尾两段，一种取中间部分。。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int cnt[n + 1];
        int maxv = 0;
        memset(cnt, 0, sizeof(cnt));
        cnt[rounds[0]] = 1;
        for(int i = 1; i < rounds.size(); i++) {
            int tmp = rounds[i - 1] + 1;
            if(tmp > n) tmp = 1;
            while(1) {
                cnt[tmp]++;
                maxv = max(maxv, cnt[tmp]);
                if(tmp == rounds[i]) break;
                tmp++;
                if(tmp > n) tmp = 1;
            }
        }
        vector<int> res;
        for(int i = 1; i <= n; i++) {
            if(cnt[i] == maxv) res.push_back(i);
        }
        return res;
    }
};
/*
 class Solution {
 public:
     vector<int> mostVisited(int n, vector<int>& rounds) {
         vector<int> res;
         int m = rounds.size();
         if(rounds[0] <= rounds[m - 1]) {
             for(int i = rounds[0]; i <= rounds[m - 1]; i++) {
                 res.push_back(i);
             }
         } else {
             for(int i = 1; i <= rounds[m - 1]; i++) {
                 res.push_back(i);
             }
             for(int i = rounds[0]; i <= n; i++) {
                 res.push_back(i);
             }
         }
         return res;
     }
 };
 */
