//
//  main.cpp
//  非常经典的题目
//  比较快的方法就是二分然后贪心check
//  另外一种做法用dp，dp[i][j]表示前i个数 分成j部分的最小最大值，然后穷举最后一部分k-i
//  dp[i][j]=min{max(dp[k-1][j-1], s[k...i])}
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int check(vector<int>& nums, int mid, int m) {
        int parts = 1, now = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (now + nums[i] <= mid) {
                now += nums[i];
            }
            else {
                parts++;
                now = nums[i];
            }
        }
        return parts <= m;
    }
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size(), s = 0, maxv = 0;
        for (int num: nums) s += num, maxv = max(maxv, num);
        int l = maxv, r = s;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(nums, mid, m)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
