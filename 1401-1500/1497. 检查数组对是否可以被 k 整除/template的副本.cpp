//
//  main.cpp
//  看余数个匹配
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int cnt[100010];
        memset(cnt, 0, sizeof(cnt));
        for (int x: arr) cnt[((x + k) % k + k) % k]++;
        for (int i = 1; i < (k + 1) /2; i++) {
            if (cnt[i] != cnt[k - i]) return false;
        }
        if (k % 2 == 0 && cnt[k / 2] % 2) return false;
        return true;
    }
};
