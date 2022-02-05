//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int sum[100010];
    int getsum(int l, int r) {
        if (l > r) return 0;
        return l ? sum[r] - sum[l - 1] : sum[r];
    }
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        sum[0] = nums[0];
        for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + nums[i];
        vector<int> res;
        int maxv = -1;
        for (int i = 0; i <= n; i++) {
            int s1 = getsum(0, i - 1), s2 = getsum(i, n - 1);
            int score = i - s1 + s2;
            if (score > maxv) {
                maxv = score;
                res = {i};
            } else if (score == maxv) {
                res.push_back(i);
            }
        }
        return res;
    }
};