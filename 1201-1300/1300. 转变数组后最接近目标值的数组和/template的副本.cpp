//
//  main.cpp
//  由于数据范围在10^5以内，我选择直接穷举这个value
//  因为对于一个value，我们可以用双指针同步算出有多少个数大于value
//  在前缀和的基础上可以直接求出对于一个value的和，所以就ok了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), now = 0, resv = INT_MAX, res = -1;
        int s[n];
        s[0] = arr[0];
        for (int i = 1; i < n; i++) s[i] = s[i - 1] + arr[i];
        for (int i = 0; i <= 100000; i++) {
            while (now < n && arr[now] <= i) now++;
            int tmpv = abs(((now ? s[now - 1] : 0) + i * (n - now)) - target);
            if (tmpv < resv) {
                resv = tmpv;
                res = i;
            }
        }
        return res;
    }
};
