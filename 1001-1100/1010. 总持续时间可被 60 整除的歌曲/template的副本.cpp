//
//  main.cpp
//  居然是中等题？数据范围还很小，变量名还用time。。有点迷啊
//  把time里的数模上60，在cnt里计数
//  除了0和30都是需要两个自身，其他都直接cnt[i]*cnt[60-i]就行
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0, n = time.size();
        int cnt[60];
        memset(cnt, 0, sizeof(cnt));
        for (int num: time) {
            cnt[num % 60]++;
        }
        res = cnt[0] * (cnt[0] - 1) / 2 + cnt[30] * (cnt[30] - 1) / 2;
        for (int i = 1; i < 30; i++) {
            res += cnt[i] * cnt[60 - i];
        }
        return res;
    }
};
