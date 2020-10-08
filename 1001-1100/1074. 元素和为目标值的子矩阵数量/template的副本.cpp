//
//  main.cpp
//  一道比较容易的困难题，从数据量可以看出O(n^3)应该是可行的
//  穷举两列，然后记录这两列之前有过的和，就只需要n^3了
//  Copyright © 2020 ji luyang. All rights reserved.
//
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        int s[m + 1][n + 1];
        memset(s, 0, sizeof(s));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                s[i][j] = s[i][j - 1] + matrix[i - 1][j - 1];
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                unordered_map<int, int> cnt;
                cnt[0] = 1;
                int tmp = 0;
                for(int k = 1; k <= m; k++) {
                    tmp += s[k][j] - s[k][i - 1];
                    if(cnt.count(tmp - target)) {
                        res += cnt[tmp - target];
                    }
                    cnt[tmp]++;
                }
            }
        }
        return res;
    }
};
