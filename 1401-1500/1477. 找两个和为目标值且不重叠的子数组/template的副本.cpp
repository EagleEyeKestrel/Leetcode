//
//  main.cpp
//  不难，a[i]表示以arr[i]结尾 且和为target的子数组的长度（没有的话是1e9）
//  b[i]是min(a[1],a[2]...a[i])。只需看a[i]+b[i-a[i]]的最小值即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int a[n], b[n];
        for (int i = 0; i < n; i++) a[i] = 1e9;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int s = 0, res = 1e9, now = 1e9;
        for (int i = 0; i < n; i++) {
            s += arr[i];
            if (mp.count(s - target)) {
                a[i] = i - mp[s - target];
            }
            mp[s] = i;
        }
        for (int i = 0; i < n; i++) {
            now = min(a[i], now);
            b[i] = now;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == 1e9 || i - a[i] < 0 || b[i - a[i]] == 1e9) continue;
            res = min(res, a[i] + b[i - a[i]]);
        }
        return res != 1e9 ? res : -1;
    }
};
