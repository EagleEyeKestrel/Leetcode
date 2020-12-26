//
//  main.cpp
//  排序+双指针，以b为基准，寻找a中大于等于b[r]的最小元素。
//  和b[r]相差最小的要么是a[l],要么是a[l-1]
//  其实这道题WA的我估计都是没注意要用long。。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long m = a.size(), n = b.size(), res = INT_MAX, l = 0;
        for (int r = 0; r < n; r++) {
            while (l < m && a[l] < b[r]) l++;
            if (l < m) res = min(res, abs((long)a[l] - b[r]));
            if (l) res = min(res, abs((long)a[l - 1] - b[r]));
        }
        return (int)res;
    }
};
