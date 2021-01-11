//
//  main.cpp
//  https://blog.csdn.net/u014156276/article/details/112473399
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxValueAfterReverse(vector<int>& a) {
        int n = a.size(), res = 0;
        for (int i = 1; i < n; i++) {
            res += abs(a[i] - a[i - 1]);
        }
        int tmp = 0, lmax = INT_MIN;
        for (int l = 1; l < n - 1; l++) {
            tmp = max(tmp, abs(a[n - 1] - a[l - 1]) - abs(a[l] - a[l - 1]));
        }
        for (int r = 1; r < n - 1; r++) {
            tmp = max(tmp, abs(a[r + 1] - a[0]) - abs(a[r + 1] - a[r]));
        }
        for (int r = 1; r < n - 1; r++) {
            if (lmax != INT_MIN) {
                tmp = max(tmp, a[r + 1] + a[r] - abs(a[r + 1] - a[r]) + lmax);
            }
            lmax = max(lmax, -a[r] - a[r - 1] - abs(a[r] - a[r - 1]));
        }
        lmax = INT_MIN;
        for (int r = 1; r < n - 1; r++) {
            if (lmax != INT_MIN) {
                tmp = max(tmp, a[r + 1] - a[r] - abs(a[r + 1] - a[r]) + lmax);
            }
            lmax = max(lmax, -a[r] + a[r - 1] - abs(a[r] - a[r - 1]));
        }
        lmax = INT_MIN;
        for (int r = 1; r < n - 1; r++) {
            if (lmax != INT_MIN) {
                tmp = max(tmp, -a[r + 1] + a[r] - abs(a[r + 1] - a[r]) + lmax);
            }
            lmax = max(lmax, a[r] - a[r - 1] - abs(a[r] - a[r - 1]));
        }
        lmax = INT_MIN;
        for (int r = 1; r < n - 1; r++) {
            if (lmax != INT_MIN) {
                tmp = max(tmp, -a[r + 1] - a[r] - abs(a[r + 1] - a[r]) + lmax);
            }
            lmax = max(lmax, a[r] + a[r - 1] - abs(a[r] - a[r - 1]));
        }
        return tmp + res;
    }
};
