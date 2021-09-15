//
//  main.cpp
//  很经典的问题，对已到达的位置存一个加油站的堆，每次优先选择油最多的加油站加油
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size() + 1, res = 0, now = startFuel, reach = 0;
        priority_queue<pair<int, int>> pq;
        stations.push_back({target, 0});
        for (int i = 0; i < n; i++) {
            while (stations[i][0] - reach > now) {
                if (pq.empty()) return -1;
                auto tmp = pq.top();
                pq.pop();
                res++;
                now += tmp.first;
            }
            now -= (stations[i][0] - reach);
            reach = stations[i][0];
            pq.push({stations[i][1], stations[i][0]});
        }
        return res;
    }
};
