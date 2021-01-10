//
//  main.cpp
//  dfs回溯
//  如果一个个回溯肯定超时，这里一次安排两个数（每次放的是一个数的左边那个）
//  pos是索引
//  要注意for里面的第一句后面两个别忘了加i>1，比赛的时候没加，一直WA，最后也没来得及找到错误。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int vis[21];
    int success = 0;
    void dfs(vector<int>& res, int pos, int n) {
        if (pos == 2 * n - 1) {
            success = 1;
            return;
        }
        if (res[pos]) {
            dfs(res, pos + 1, n);
            return;
        }
        for (int i = n; i >= 1; i--) {
            if (vis[i] || i > 1 && pos + i >= 2 * n - 1 || i > 1 && res[pos + i]) continue;
            vis[i] = 1;
            res[pos] = i;
            if (i > 1) res[pos + i] = i;
            dfs(res, pos + 1, n);
            if (success) return;
            res[pos] = 0;
            if (i > 1) res[i + pos] = 0;
            vis[i] = 0;
        }
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2 * n - 1, 0);
        memset(vis, 0, sizeof(vis));
        dfs(res, 0, n);
        return res;
    }
};
