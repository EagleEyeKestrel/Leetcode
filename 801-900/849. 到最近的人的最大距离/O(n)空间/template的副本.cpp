//
//  main.cpp
//  比较一般的做法，遍历两次得到最大的最小距离
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int d[n];
        int now = 1e6, res = 0;
        for(int i = 0; i < n; i++) {
            if(seats[i]) {
                now = 0;
                d[i] = 0;
            } else {
                now++;
                d[i] = now;
            }
        }
        now = 1e6;
        for(int i = n - 1; i >= 0; i--) {
            if(seats[i]) {
                now = 0;
            } else {
                now++;
                d[i] = min(d[i], now);
                res = max(res, d[i]);
            }
        }
        return res;
    }
};
