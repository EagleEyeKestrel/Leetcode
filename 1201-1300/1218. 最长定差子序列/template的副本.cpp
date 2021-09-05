//
//  main.cpp
//  比较简单，dp[i]表示arr[i]结尾的最长序列长度
//  mp存储元素到索引的映射。直接找arr[i]-d是否存在
//  注意对同一个值，mp只需要维护最右边的位置就行了。因为最右边的解肯定更优
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size(), res = 1;
        int dp[n];
        dp[0] = 1;
        unordered_map<int, int> mp;
        mp[arr[0]] = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            int j = arr[i] - difference;
            if (mp.count(j)) {
                dp[i] = dp[mp[j]] + 1;
            }
            mp[arr[i]] = i;
            res = max(res, dp[i]);
        }
        return res;
    }
};
