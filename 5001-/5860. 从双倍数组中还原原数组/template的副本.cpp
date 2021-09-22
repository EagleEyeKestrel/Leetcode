//
//  main.cpp
//  每次拿出来最大的数maxv，同时原数组一定存在maxv/2
//  开始用multiset居然超时了。。。哎，不应该，只能换数组模拟
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> res;
        int cnt[100010];
        memset(cnt, 0, sizeof(cnt));
        for (int x: changed) cnt[x]++;
        if (changed.size() % 2) return {};
        int rest = changed.size();
        int maxv = 1e5;
        while (maxv >= 0 && cnt[maxv] == 0) maxv--;
        while (rest > 0) {
            cnt[maxv]--;
            if (maxv % 2 || cnt[maxv / 2] == 0) return {};
            res.push_back(maxv / 2);
            cnt[maxv / 2]--;
            while (maxv >= 0 && cnt[maxv] == 0) maxv--;
            rest -= 2;
        }
        return res;
    }
};
