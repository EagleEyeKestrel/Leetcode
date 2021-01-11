//
//  main.cpp
//  我的解法：贪心。本质是把一堆数配成(a,2a)的形式
//  我用了两个map，存储正数和负数的出现次数，以及0的个数
//  0只能有偶数个，然后按绝对值从小到大考虑，k只能用2k来匹配。
//  评论区看到别人把两个map合一的写法，看注释，更简洁
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int, int> mpos, mneg;
        int zero = 0;
        for (int x: A) {
            if (x > 0) mpos[x]++;
            else if (x < 0) mneg[x]++;
            else zero++;
        }
        if (zero % 2) return false;
        for (auto it : mpos) {
            int key = it.first, val = it.second;
            if (!val) continue;
            auto it2 = mpos.find(key << 1);
            if (it2 == mpos.end() || it2->second < val) return false;
            it2->second -= val;
        }
        for (auto it = mneg.rbegin(); it != mneg.rend(); it++) {
            int key = it->first, val = it->second;
            if (!val) continue;
            auto it2 = mneg.find(2 * key);
            if (it2 == mneg.end() || it2->second < val) return false;
            it2->second -= val;
        }
        return true;

    }
};

/*
 class Solution {
 public:
     bool canReorderDoubled(vector<int>& A) {
         map<double, double> m;
         for (auto& num : A) {
             m[num]++;
         }
         for (auto& [c, d] : m) {
             if (d < 0) return false;
             if (d == 0) continue;
             if (c > 0) {
                 if (!m.count(c * 2)) return false;
                 m[c * 2] -= d;
             } else {
                 if (!m.count(c / 2.0)) return false;
                 m[c / 2.0] -= d;
             }
         }
         return true;
     }
 };
 */
