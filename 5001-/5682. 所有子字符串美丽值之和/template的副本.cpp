//
//  main.cpp
//  对每个子串来算 用前缀和处理一下就好了 复杂度O(26n2) 稳过
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), res = 0;
        int sum[n + 1][26];
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 26; j++) {
                if (s[i - 1] == j + 'a') sum[i][j] = sum[i - 1][j] + 1;
                else sum[i][j] = sum[i - 1][j];
            }
        }
        for (int l = 1; l <= n; l++) {
            for (int r = l; r <= n; r++) {
                int tmp[26];
                int minv = INT_MAX, maxv = 0;
                for (int k = 0; k < 26; k++) {
                    tmp[k] = sum[r][k] - sum[l - 1][k];
                }
                for (int k = 0; k < 26; k++) {
                    if (!tmp[k]) continue;
                    maxv = max(maxv, tmp[k]);
                    minv = min(minv, tmp[k]);
                }
                res += maxv - minv;
            }
        }
        return res;
    }
};
