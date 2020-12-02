//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size(), tmp = 0, now = start, sum = 0;
        for(int x: distance) sum += x;
        while(now != destination) {
            tmp += distance[now];
            now = (now + 1) % n;
        }
        return min(tmp, sum - tmp);
    }
};
