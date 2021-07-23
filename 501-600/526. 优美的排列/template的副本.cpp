//
//  main.cpp
//  比较基础的回溯
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int res = 0;
    vector<int> tmp;
    void dfs(int mask, int n) {
        if (tmp.size() == n) {
            res++;
            return;
        }
        int i = tmp.size() + 1;
        for (int k = 1; k <= n; k++) {
            if (((mask >> k) & 1) == 0 && (i % k == 0 || k % i == 0)) {
                tmp.push_back(k);
                dfs(mask | (1 << k), n);
                tmp.pop_back();
            }
        }
    }
    int countArrangement(int n) {
        dfs(0, n);
        return res;
    }
};
