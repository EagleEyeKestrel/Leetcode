//
//  main.cpp
//  关键是，第二个人能获得的分数只能是第一行的最后，或者是第二段的开头
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long minv = 1e16, id = -1;
        long long s1[n], s2[n];
        s1[0] = grid[0][0], s2[0] = grid[1][0];
        for (int i = 1; i < n; i++) s1[i] = s1[i - 1] + grid[0][i];
        for (int i = 1; i < n; i++) s2[i] = s2[i - 1] + grid[1][i];
        for (int i = 0; i < n; i++) {
            long long val1 = i > 0 ? s2[i - 1] : 0;
            long long val2 = s1[n - 1] - s1[i];
            long long score = max(val1, val2);
            if (score < minv) {
                id = i;
                minv = score;
            }
        }
        return minv;
    }
};
