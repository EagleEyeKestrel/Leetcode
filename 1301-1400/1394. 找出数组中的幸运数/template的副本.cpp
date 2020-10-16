//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int cnt[512];
        memset(cnt, 0, sizeof(cnt));
        for(int x: arr) cnt[x]++;
        for(int i = 500; i >= 1; i--) {
            if(cnt[i] == i) return i;
        }
        return -1;
    }
};
