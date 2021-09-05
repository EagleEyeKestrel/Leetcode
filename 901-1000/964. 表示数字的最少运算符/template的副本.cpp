//
//  main.cpp
//  记忆化搜索
//  对于target,找到最小的x*x*...x >= target
//  无非第一种是加到x*x*...x 然后减到target 或者用x...x(少一个) 加到target
//  注意一种情况 比如说x=3 target=4，那就会重复计算f(3,4) f(3,5) f(3,4)
//  所以要加上v[id]-target<target的限制
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    unordered_map<long long, int> mp;
    vector<long long> v;
    int f(int x, long long target) {
        if (target <= 1) return target;
        if (target < x) return min(2 * target - 1, 2 * (x - target));
        if (mp.count(target)) return mp[target];
        int id = lower_bound(v.begin(), v.end(), target) - v.begin();
        int res = INT_MAX;
        if (v[id] - target < target) res = f(x, v[id] - target) + (v[id] - target == 0 ? id : id + 1);
        if (id > 0) res = min(res, f(x, target - v[id - 1]) + id);
        mp[target] = res;
        return res;
    }
    int leastOpsExpressTarget(int x, int target) {
        long long now = x;
        while (now < 1e12) {
            v.push_back(now);
            now *= x;
        }
        return f(x, target);
    }
};
