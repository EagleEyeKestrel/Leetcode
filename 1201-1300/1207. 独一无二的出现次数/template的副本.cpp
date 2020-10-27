//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int cnt[2048];
        memset(cnt, 0, sizeof(cnt));
        for(int x: arr) cnt[x + 1000]++;
        sort(cnt, cnt + 2048);
        for(int i = 1; i < 2048; i++) {
            if(cnt[i] == cnt[i - 1] && cnt[i]) return false;
        }
        return true;
    }
};
