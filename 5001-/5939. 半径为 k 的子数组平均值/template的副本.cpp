//
//  main.cpp
//  前缀和
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        long long s[n];
        s[0] = nums[0];
        for (int i = 1; i < n; i++) s[i] = s[i - 1] + nums[i];
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (i - k < 0 || i + k >= n) res[i] = -1;
            else res[i] = (s[i + k] - (i - k - 1 >= 0 ? s[i - k - 1] : 0)) / (2 * k + 1);
        }
        return res;
    }
};
