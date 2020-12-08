//
//  main.cpp
//  二分贪心的典型题
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(vector<int>& position, int m, int mid) {
        int tmp = 1, last = 0;
        for(int i = 1; i < position.size(); i++) {
            if(position[i] - position[last] >= mid) {
                tmp++;
                last = i;
            }
        }
        return tmp >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1, r = position.back() - position[0];
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(f(position, m, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
