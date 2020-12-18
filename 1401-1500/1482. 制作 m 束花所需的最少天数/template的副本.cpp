//
//  main.cpp
//  当发现确定一个结果进行检验只需要O(n)的时候，就知道肯定要二分了。。
//  每次取花贪心取就可以了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int check(int mid, vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), res = 0, tmp = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= mid) tmp++;
            else tmp = 0;
            if (tmp == k) {
                tmp = 0;
                res++;
            }
        }
        return res >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < (long)m * k) return -1;
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid, bloomDay, m, k)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
