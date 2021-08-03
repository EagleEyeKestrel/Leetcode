//
//  main.cpp
//  数据范围非常小，直接枚举全排列即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size(), n = students[0].size(), res = 0;
        int a[m];
        for (int i = 0; i < m; i++) {
            a[i] = i;
        }
        do {
            int tmp = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (students[a[i]][j] == mentors[i][j]) tmp++;
                }
            }
            res = max(res, tmp);
        }while (next_permutation(a, a + m));
        return res;
    }
};
