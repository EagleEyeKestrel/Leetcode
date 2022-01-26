//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size(), res = 0;
        for (int i = 0; i < k; i++) {
            vector<int> v, dp;
            for (int j = i; j < n; j += k) v.push_back(arr[j]);
            for (int x: v) {
                if (dp.empty() || dp.back() <= x) {
                    dp.push_back(x);
                } else {
                    *upper_bound(dp.begin(), dp.end(), x) = x;
                }
            }
            res += v.size() - dp.size();
        }
        return res;
    }
};
