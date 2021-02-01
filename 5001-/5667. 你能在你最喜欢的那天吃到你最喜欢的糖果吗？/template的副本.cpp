//
//  main.cpp
//  好气啊，这题就是考边界
//  看两种边界情况能吃到哪个类型的糖。
//  一种是每天只吃一个，另一种是每天尽力吃，关键是lower/upper, 是t+1还是t，要小心
//  想了好久怎么理解比较好，现在是这么理解的
//  到第t天吃的最后一个糖是cap * (t + 1)，看第多少天的前缀和是大于等于这个数，那就说明在吃这个类型
//  或者就用sum[type]去和两种情况比较，同样可以
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<bool> res(queries.size());
        int n = candiesCount.size();
        long long sum[n];
        sum[0] = candiesCount[0];
        for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + candiesCount[i];
        for (int i = 0; i < queries.size(); i++) {
            int type = queries[i][0], t = queries[i][1], cap = queries[i][2];
            int id1 = lower_bound(sum, sum + n, t + 1) - sum;
            int id2 = lower_bound(sum, sum + n, (long long)cap * (t + 1)) - sum;
            res[i] = (type >= id1 && type <= id2);
        }
        return res;
    }
};
