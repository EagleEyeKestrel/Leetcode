//
//  main.cpp
//  二分check就可以了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int check(vector<int>& dist, int speed, double hour) {
        double res = 0;
        for (int i = 0; i < dist.size(); i++) {
            int s = dist[i];
            if (i < dist.size() - 1) res += s / speed + (s % speed != 0);
            else res += (double)s / speed;
        }
        return res <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (hour <= dist.size() - 1) return -1;
        int l = 1, r = 1e7;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(dist, mid, hour)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
