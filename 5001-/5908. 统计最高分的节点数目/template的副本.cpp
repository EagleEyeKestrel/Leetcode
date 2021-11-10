//
//  main.cpp
//  比较简单，预处理每一个子树的大小即可。然后每个节点至多由三部分分数组成，两个儿子，一个父亲
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> g[100010];
    long long sz[100010], scores[100010];
    int dfs(int i) {
        int tmp = 1;
        for (int j: g[i]) {
            tmp += dfs(j);
        }
        sz[i] = tmp;
        return tmp;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        for (int i = 0; i < n; i++) {
            if (i) g[parents[i]].push_back(i);
        }
        sz[0] = dfs(0);
        long long maxv = 0;
        for (int i = 0; i < n; i++) {
            vector<long long> v;
            int sum = 1;
            for (int j: g[i]) v.push_back(sz[j]), sum += sz[j];
            if (i) v.push_back(n - sum);
            long long score = 1;
            for (int x: v) score *= x;
            scores[i] = score;
            maxv = max(maxv, score);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (scores[i] == maxv) cnt++;
        }
        return cnt;
    }
};
