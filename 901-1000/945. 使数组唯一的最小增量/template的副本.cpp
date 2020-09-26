//
//  main.cpp
//  把A转化成统计数组。当cnt[i]>1，把cnt[i]-1个i都加1，变成i+1。
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int n = A.size(), res = 0;
        int cnt[40010];
        memset(cnt, 0, sizeof(cnt));
        for(int a: A) cnt[a]++;
        for(int i = 0; i < 40000; i++) {
            if(cnt[i] > 1) {
                cnt[i + 1] += cnt[i] - 1;
                res += cnt[i] - 1;
            }
        }
        if(cnt[40000]) {
            res += cnt[40000] * (cnt[40000] - 1) / 2;
        }
        return res;
    }
};
