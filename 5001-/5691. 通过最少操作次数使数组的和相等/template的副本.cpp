//
//  main.cpp
//  贪心的修改，如果两个数组的和不相等，那么优先修改大数组里的6和小数组里的1
//  一次可以把差距减小5 。如果修改完了，再去修改大数组里的5和小数组里的2，依次下去
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int cnt1[7], cnt2[7];
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for (int num: nums1) cnt1[num]++;
        for (int num: nums2) cnt2[num]++;
        int sum1 = 0, sum2 = 0;
        for (int i = 1; i <= 6; i++) {
            sum1 += cnt1[i] * i;
            sum2 += cnt2[i] * i;
        }
        if (sum1 == sum2) return 0;
        if (sum1 > sum2) {
            for (int i = 1; i <= 6; i++) swap(cnt1[i], cnt2[i]);
        }
        int diff = abs(sum1 - sum2), res = 0;
        for (int i = 5; i >= 1; i--) {
            int k = cnt1[6 - i] + cnt2[1 + i];
            if (diff > k * i) {
                res += k;
                diff -= k * i;
            } else {
                res += diff % i ? diff / i + 1 : diff / i;
                diff = 0;
                break;
            }
        }
        return diff == 0 ? res : -1;
    }
};
