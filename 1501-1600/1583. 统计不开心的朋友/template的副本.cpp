//
//  main.cpp
//  理解题意是成功的一半。。
//  g[i][j]表示对于i，j的排名 cp[i]表示i的cp
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int g[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - 1; j++) {
                g[i][preferences[i][j]] = j;
            }
        }
        int cp[n];
        for(int i = 0; i < n / 2; i++) {
            cp[pairs[i][0]] = pairs[i][1];
            cp[pairs[i][1]] = pairs[i][0];
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (j == cp[i] || j == i) continue;
                int rankofcpi = g[i][cp[i]], rankofj = g[i][j];
                int rankofcpj = g[j][cp[j]], rankofi = g[j][i];
                if (rankofcpi > rankofj && rankofcpj > rankofi) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
