//
//  main.cpp
//  dp，可以用Bellman Ford类似的方法，k次中转其实就是最多k+1步，遍历(k+1)m次就可以了
//  如果是按kn来遍历应该也可以？就是需要先建一下图
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int m = flights.size();
        int dp[K + 2][n];
        for(int k = 0; k <= K + 1; k++) {
            for(int i = 0; i < n; i++) {
                dp[k][i] = 1e9;
            }
        }
        for(int k = 0; k <= K + 1; k++) dp[k][src] = 0;
        for(int k = 1; k <= K + 1; k++) {
            for(auto &flight: flights) {
                dp[k][flight[1]] = min(dp[k][flight[1]], dp[k - 1][flight[0]] + flight[2]);
            }
        }
        if(dp[K + 1][dst] == 1e9) return -1;
        return dp[K + 1][dst];
    }
};
