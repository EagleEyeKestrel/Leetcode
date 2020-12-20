//
//  main.cpp
//  https://blog.csdn.net/u014156276/article/details/111465322
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int p[100010], rank[100010];

    int findp(int x) {
        if (p[x] != x) {
            p[x] = findp(p[x]);
        }
        return p[x];
    }

    void merge(int x, int y) {
        int px = findp(x), py = findp(y);
        if (rank[px] <= rank[py]) p[px] = py;
        else p[py] = px;
        if (rank[px] == rank[py] && px != py) rank[py]++;
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int qsize = queries.size();
        vector<bool> res(qsize);
        for (int i = 0; i < n; i++) p[i] = i, rank[i] = 1;
        int qid[100010];
        for (int i = 0; i < qsize; i++) qid[i] = i;
        sort(edgeList.begin(), edgeList.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });
        sort(qid, qid + qsize, [&queries](int a, int b) {
            return queries[a][2] < queries[b][2];
        });
        int j = -1;
        for (int i = 0; i < qsize; i++) {
            while (j + 1 < edgeList.size() && edgeList[j + 1][2] < queries[qid[i]][2]) {
                j++;
                merge(edgeList[j][0], edgeList[j][1]);
            }
            res[qid[i]] = findp(queries[qid[i]][0]) == findp(queries[qid[i]][1]);
        }
        return res;
    }
};
