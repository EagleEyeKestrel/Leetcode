//
//  main.cpp
//  O(mn)的解法
//  https://blog.csdn.net/u014156276/article/details/108544462
//  之前重点学习过 长方形的单调栈解法
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int h[200], l[200], r[200];
    int m, n;
    void fl() {
        stack<int> s;
        for (int j = n - 1; j >= 0; j--) {
            while (!s.empty() && h[j] <= h[s.top()]) {
                l[s.top()] = j;
                s.pop();
            }
            s.push(j);
        }
        while (!s.empty()) {
            l[s.top()] = -1;
            s.pop();
        }
    }
    void fr() {
        stack<int> s;
        for (int j = 0; j < n; j++) {
            while (!s.empty() && h[j] < h[s.top()]) {
                r[s.top()] = j;
                s.pop();
            }
            s.push(j);
        }
        while (!s.empty()) {
            r[s.top()] = n;
            s.pop();
        }
    }
    int numSubmat(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) h[j] = mat[i][j];
                else {
                    if (mat[i][j] == 0) h[j] = 0;
                    else h[j]++;
                }
            }
            fl();
            fr();
            for (int j = 0; j < n; j++) {
                res += (j - l[j]) * (r[j] - j) * h[j];
            }
        }
        return res;
    }
};
