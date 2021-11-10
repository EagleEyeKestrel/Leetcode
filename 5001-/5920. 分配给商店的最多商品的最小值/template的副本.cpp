//
//  main.cpp
//  最基础的二分check
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int check(long long mid, int n, vector<int> &q) {
        int m = q.size();
        long long cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += (q[i] + mid - 1) / mid;
        }
        return cnt <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long l = 1, r = 1e10;
        while (l < r) {
            long long mid = (l + r) >> 1;
            if (check(mid, n, quantities)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
