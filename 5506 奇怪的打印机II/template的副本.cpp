//
//  main.cpp
//  https://blog.csdn.net/u014156276/article/details/108688392
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int m = targetGrid.size(), n = targetGrid[0].size(), colors = 0;
        int ind[61], vis[61];
        int graph[61][61];
        int a[61][4];
        memset(ind, 0, sizeof(ind));
        memset(vis, 0, sizeof(vis));
        memset(graph, 0, sizeof(graph));
        for(int i = 1; i <= 60; i++) {
            a[i][0] = INT_MAX;
            a[i][1] = INT_MAX;
            a[i][2] = -1;
            a[i][3] = -1;
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vis[targetGrid[i][j]] = 1;
                a[targetGrid[i][j]][0] = min(a[targetGrid[i][j]][0], i);
                a[targetGrid[i][j]][1] = min(a[targetGrid[i][j]][1], j);
                a[targetGrid[i][j]][2] = max(a[targetGrid[i][j]][2], i);
                a[targetGrid[i][j]][3] = max(a[targetGrid[i][j]][3], j);
            }
        }
        for(int i = 1; i <= 60; i++) {
            if(!vis[i]) continue;
            colors++;
            for(int ii = a[i][0]; ii <= a[i][2]; ii++) {
                for(int jj = a[i][1]; jj <= a[i][3]; jj++) {
                    if(targetGrid[ii][jj] != i) {
                        if(!graph[i][targetGrid[ii][jj]]) ind[targetGrid[ii][jj]]++;
                        graph[i][targetGrid[ii][jj]] = 1;
                    }
                }
            }
        }
        queue<int> q;
        int cnt = 0;
        for(int i = 1; i <= 60; i++) {
            if(vis[i] && ind[i] == 0) {
                q.push(i);
                cnt++;
            }
        }
        while(!q.empty()) {
            int tmp = q.front();
            q.pop();
            for(int j = 1; j <= 60; j++) {
                if(graph[tmp][j]) {
                    ind[j]--;
                    if(ind[j] == 0) {
                        cnt++;
                        q.push(j);
                    }
                }
            }
        }
        return cnt == colors;
    }
};
