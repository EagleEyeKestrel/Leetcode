//
//  main.cpp
//  比较基础的图论题，floyd得到两两之间的距离，然后就挨个进行统计
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dist[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = 1e9;
            }
        }
        for (auto &edge: edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int num[n];
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (dist[i][j] <= distanceThreshold) num[i]++;
            }
        }
        int resv = n, resid = 0;
        for (int i = 0; i < n; i++) {
            if (num[i] <= resv) {
                resv = num[i];
                resid = i;
            }
        }
        return resid;
    }
};
