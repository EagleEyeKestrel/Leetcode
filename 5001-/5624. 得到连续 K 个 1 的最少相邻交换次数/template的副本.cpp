//
//  main.cpp
//  https://blog.csdn.net/u014156276/article/details/111825930
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) s.push_back(i - s.size());
        }
        int cnt = s.size(), res = INT_MAX;
        int spre[cnt + 1];
        spre[0] = 0;
        for (int i = 1; i <= cnt; i++) spre[i] = spre[i - 1] + s[i - 1];
        for (int i = 0; i <= cnt - k; i++) {
            int mid = (i + i + k - 1) >> 1;
            int s1 = spre[mid] - spre[i], s2 = spre[i + k] - spre[mid + 1];
            res = min(res, (2 * (mid - i) - k + 1) * s[mid] - s1 + s2);
        }
        return res;
    }
};
