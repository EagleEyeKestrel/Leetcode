//
//  main.cpp
//  https://blog.csdn.net/u014156276/article/details/116566449
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int mod = 1e9 + 7, n = nums.size();
        int r[n], l[n];
        long long res = 0;
        for (int i = 0; i < n; i++) r[i] = n, l[i] = -1;
        stack<int> s;
        long long spre[n + 1];
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[i] < nums[s.top()]) {
                r[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[i] < nums[s.top()]) {
                l[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        spre[0] = 0;
        for (int i = 1; i <= n; i++) spre[i] = spre[i - 1] + nums[i - 1];
        for (int i = 0; i < n; i++) {
            res = max(res, (long long)nums[i] * (spre[r[i]] - spre[l[i] + 1]));
        }
        return res % mod;
    }
};
