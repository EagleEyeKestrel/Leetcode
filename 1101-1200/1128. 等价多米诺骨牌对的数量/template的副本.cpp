//
//  main.cpp
//  很简单的题，朴素的排序肯定也可以过
//  注意到数的范围<=9，可以把一个长宽对，映射到一个数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size(), res = 0;
        int cnt[100];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            int minv = min(dominoes[i][0], dominoes[i][1]);
            int maxv = max(dominoes[i][0], dominoes[i][1]);
            int tmp = 10 * minv + maxv;
            res += cnt[tmp];
            cnt[tmp]++;
        }
        return res;
    }
};
