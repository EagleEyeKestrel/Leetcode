//
//  main.cpp
//  滑动窗口题，找到能提升满意度的最大的长度为X的区间
//  结果就是原来的满意度，加上这个提升量
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size(), tmp = 0, l = 0, maxv = 0, sum = 0;
        for (int r = 0; r < n; r++) {
            if (grumpy[r]) {
                tmp += customers[r];
            }
            if (r - l + 1 > X) {
                if (grumpy[l]) tmp -= customers[l];
                l++;
            }
            if (r - l + 1 >= X) {
                maxv = max(maxv, tmp);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!grumpy[i]) sum += customers[i];
        }
        return maxv + sum;
    }
};
