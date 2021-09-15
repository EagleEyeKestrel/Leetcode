//
//  main.cpp
//  感觉这应该是更正统的做法，折半查找
//  把每个数减去平均值，然后再找是否存在一个子序列的和为0。
//  分两半v1和v2，三种情况，一种子序列在v1中/在v2中，既在v1又在v2的情况用双指针/二分即可
//  注意减去平均值的技巧：把每个数都乘以n不影响结果。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    void f(vector<int> &v, vector<int> &se) {
        int n = v.size();
        for (int mask = 1; mask < 1 << n; mask++) {
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) tmp += v[i];
            }
            se.push_back(tmp);
        }
    }
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(), s = 0;
        if (n == 1) return false;
        for (int i = 0; i < n; i++) nums[i] *= n;
        for (int i = 0; i < n; i++) s += nums[i];
        int avg = s / n;
        for (int i = 0; i < n; i++) nums[i] -= avg;
        vector<int> l, r;
        vector<int> v1(nums.begin(), nums.begin() + n / 2);
        vector<int> v2(nums.begin() + n / 2, nums.end());
        f(v1, l), f(v2, r);
        for (int x: l) if (x == 0) return true;
        for (int x: r) if (x == 0) return true;
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        int p = r.size() - 1, res = 0;
        for (int i = 0; i < l.size(); i++) {
            while (p >= 0 && r[p] + l[i] > 0) p--;
            if (p < 0) break;
            if (r[p] + l[i] == 0) res++;
        }
        return res > 1;
    }
};
