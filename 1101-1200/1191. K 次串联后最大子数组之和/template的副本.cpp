//
//  main.cpp
//  如果结果子数组的长度不超过2n,直接处理
//  如果结果子数组的长度大于2n，那里面一定有完整的arr数组。那arr数组的元素和一定>0，否则这一段可以删掉，和可以更大。
//  所以找到arr最大的和前缀，最大的和后缀，加上k-2个arr数组即可。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long sum = 0, mod = 1e9 + 7, n = arr.size();
        for (int x: arr) sum += x;
        vector<int> v = arr;
        if (k > 1) {
            for (int x: arr) v.push_back(x);
        }
        long long res = 0, nows = 0, mins = 0;
        for (int i = 0; i < v.size(); i++) {
            nows += v[i];
            res = max(res, nows - mins);
            mins = min(mins, nows);
        }
        if (k > 2 && sum > 0) {
            long long presum[n], sufsum[n];
            presum[0] = arr[0], sufsum[n - 1] = arr[n - 1];
            for (int i = 1; i < n; i++) presum[i] = presum[i - 1] + arr[i];
            for (int i = n - 2; i >= 0; i--) sufsum[i] = sufsum[i + 1] + arr[i];
            long long maxpre = 0, maxsuf = 0;
            for (int i = 0; i < n; i++) {
                maxpre = max(maxpre, presum[i]);
                maxsuf = max(maxsuf, sufsum[i]);
            }
            res = (k - 2) * sum + maxpre + maxsuf;
        }
        return max(res, 0ll) % mod;
    }
};
