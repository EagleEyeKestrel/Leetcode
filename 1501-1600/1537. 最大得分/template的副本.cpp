//
//  main.cpp
//  有两种思路，第一种比较好想，也是我当时比赛使用的
//  双指针找到所有数值重合的地方，然后处理每一段的和取最大值即可。
//  dp的方法不容易想。可以看这里，用f[i] 表示走到nums1[i]的最大分数
//  g[j]表示走到nums2[j]的最大分数。关键是转移的方式，可以用双指针，从小到大处理，
//  关键是从小到大处理 不会错过每个相等的地方
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int mod = 1e9 + 7, m = nums1.size(), n = nums2.size();
        long long f[m], g[n];
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (i < m && j < n && nums1[i] < nums2[j] || j == n) {
                f[i] = (i ? f[i - 1] + nums1[i] : nums1[i]);
                i++;
            } else if (i < m && j < n && nums1[i] > nums2[j] || i == m) {
                g[j] = (j ? g[j - 1] + nums2[j] : nums2[j]);
                j++;
            } else {
                long long minpre = 0;
                if (i) minpre = max(minpre, f[i - 1]);
                if (j) minpre = max(minpre, g[j - 1]);
                f[i] = minpre + nums1[i];
                g[j] = f[i];
                i++, j++;
            }
        }
        return max(f[m - 1], g[n - 1]) % mod;
    }
};
