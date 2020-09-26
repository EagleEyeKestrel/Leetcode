//
//  main.cpp
//  两种情况，如果最大的就是正常子数组，那直接dp
//  如果是个环，那就等于总的和减去中间最小的子数组
//  但要注意，如果中间最小的子数组就是所有数，那么减了之后就是空了。要排除这种情况
//  这种情况，res1要<0, 说明全是负数，然后全负数最小的子数组确实就是所有数。所以特判一下
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size(), sum = 0, flag = 0, maxv = INT_MIN;
        for(int i = 0; i < n; i++) {
            sum += A[i];
            if(A[i] > 0) flag = 1;
            maxv = max(maxv, A[i]);
        }
        if(!flag) return maxv;
        int now1 = 0, now2 = 0, res1 = 0, res2 = 0;
        for(int i = 0; i < n; i++) {
            if(now1 > 0) {
                now1 += A[i];
            } else {
                now1 = A[i];
            }
            if(now2 < 0) {
                now2 += A[i];
            } else {
                now2 = A[i];
            }
            res1 = max(res1, now1);
            res2 = min(res2, now2);
        }
        return max(res1, sum - res2);
    }
};
