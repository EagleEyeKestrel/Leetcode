//
//  main.cpp
//  二分就行了
//  确定了nums[index]之后，为了让整体的和最小，肯定让左右两侧的数尽快下降
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int check(int n, int index, int maxSum, int mid) {
        int l1 = index, l2 = n - 1 - index;
        long long s1, s2;
        if (l1 <= mid - 1) s1 = (long long)(mid - 1 + mid - l1) * l1 / 2;
        else s1 = (long long)(mid - 1) * mid / 2 + (l1 - mid + 1);
        if (l2 <= mid - 1) s2 = (long long)(mid - 1 + mid - l2) * l2 / 2;
        else s2 = (long long)(mid - 1) * mid / 2 + (l2 - mid + 1);
        return s1 + s2 + mid <= maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(n, index, maxSum, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
