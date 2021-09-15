//
//  main.cpp
//  法一，可以发现对于长度l，要找到长度为l的子序列使得和为s*l/n
//  但是想到穷举l从1到30会超时，所以放弃了。但实际上l是<=15的，因为我们只需要看小一半的数组是否满足
//  用dp[sz]表示sz个数字能凑成的和 的集合
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(), s = 0;
        for (int num: nums) s += num;
        unordered_set<int> dp[n / 2 + 1];
        dp[0] = {0};
        for (int i = 0; i < n; i++) {
            for (int sz = min(i + 1, n / 2); sz >= 1; sz--) {
                for (int x: dp[sz - 1]) {
                    dp[sz].insert(x + nums[i]);
                }
            }
        }
        for (int l = 1; l <= n / 2; l++) {
            if (s * l % n) continue;
            if (dp[l].count(s * l / n)) return true;
        }
        return false;
    }
};
