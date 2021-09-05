//
//  main.cpp
//  一种方法
//  可以看作在rods里所有元素前面乘上 -1 1 或 0
//  所以可以考虑用一个哈希集合维护到rods[i]为止所有的{和，*1的和}
//  对于和重复的情况。因为我们只要1对应的元素和最大，取max即可
//  所求即为最后时刻的mp[0]。
//  此解法容易想，但是速度比较慢（虽然我也没想到
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    void add(unordered_map<int, int> &tmp, int mul, int x, int s, int pos) {
        int key = s + mul * x, newpos = (mul == 1 ? pos + x : pos);
        if (tmp.count(key)) tmp[key] = max(newpos, tmp[key]);
        else tmp[key] = newpos;
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size(), res = 0;
        unordered_map<int, int> mp;
        mp[0] = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> tmp;
            for (auto [s, pos]: mp) {
                for (int k = -1; k <= 1; k++) {
                    add(tmp, k, rods[i], s, pos);
                }
            }
            mp = tmp;
        }
        return mp[0];
    }
};
