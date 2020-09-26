//
//  main.cpp
//  基本题了，cnt[i]存储之前和为nK + i的数组个数
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int cnt[K], now = 0, res = 0;
        memset(cnt, 0, sizeof(cnt));
        cnt[0] = 1;
        for(int i = 0; i < A.size(); i++) {
            now = ((now + A[i]) % K + K) % K;
            if(cnt[now]) res += cnt[now];
            cnt[now]++;
        }
        return res;
    }
};
