//
//  main.cpp
//  设三段分别是1...  i... j...
//  满足条件：s[j-1]-s[i-1] >= s[i-1]
//          s[n]-s[j-1] >= s[j-1]-s[i-1]
//  可以得到s[j-1]的范围，对应下面的p1 p2，开始WA了一次是因为没有注意搜索的结束区间应该
//  是s+n，而非s+n+1，因为是s[j-1]的范围。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        long n = nums.size(), mod = 1e9 + 7, res = 0;
        int s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        for (int i = 2; i <= n - 1; i++) {
            int p1 = lower_bound(s + i, s + n, 2 * s[i - 1]) - s;
            int p2 = upper_bound(s + i, s + n, (s[n] + s[i - 1]) / 2.0) - s;
            if (p1 < n && p2 > p1) res = (res + p2 - p1) % mod;
        }
        return res;
    }
};
