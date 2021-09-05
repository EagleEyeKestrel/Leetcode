//
//  main.cpp
//  比较简单，用dp[i]表示arr[i]为根的树有多少种，自小到大处理
//  穷举左子树arr[j]，判断是否存在另一个子树
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) mp[arr[i]] = i;
        int n = arr.size(), res = 0;
        int dp[n];
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] || !mp.count(arr[i] / arr[j])) continue;
                dp[i] = (dp[i] + (long long)dp[j] * dp[mp[arr[i] / arr[j]]] % mod) % mod;
            }
            res = (res + dp[i]) % mod;
        }
        return res;
    }
};
