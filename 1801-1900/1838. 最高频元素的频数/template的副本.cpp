//
//  main.cpp
//  我的解法，容易发现尽可能增加一些数，使他们能够等于另一个数
//  那关键是让他们等于什么数呢？假设是nums[r]，那显然让nums[r-1],r-2...去增
//  所以其实就是对于某个nums[r]，去找最小的l是多少
//  这里用的是双指针，即滑动窗口，对于区间[l,r]，要让所有数都等于nums[r]，需要nums[r]-nums[r-1]+nums[r]-nums[r-2]...+nums[r]-nums[l]次，可以用前缀和O(1)求出来
//  或者也可以二分l，求到最小的l。一样可以
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size(), res = 1, l = 1;
        sort(nums.begin(), nums.end());
        long s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        for (int r = 2; r <= n; r++) {
            while ((long)nums[r - 1] * (r - l) - (s[r - 1] - s[l - 1]) > k) {
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
