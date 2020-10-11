//
//  main.cpp
//  最朴素的办法，如果穷举两个点再穷举所有边，就是O(n4)，会超时
//  所以预处理一下就行，建个图，然后穷举两个点，查看两个点一共有多少条连边，注意(i,j)只算一次，就变成了O(n3)
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int g[n][n];
        memset(g, 0, sizeof(g));
        for(auto &v: roads) {
            g[v[0]][v[1]] = 1;
            g[v[1]][v[0]] = 1;
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int tmp = 0;
                for(int k = 0; k < n; k++) {
                    if(g[i][k]) tmp++;
                    if(g[j][k]) tmp++;
                }
                if(g[i][j]) tmp--;
                res = max(res, tmp);
            }
        }
        return res;
    }
};
