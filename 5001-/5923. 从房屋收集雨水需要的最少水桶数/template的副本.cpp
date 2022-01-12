//
//  main.cpp
//  每次遇到房子，要放桶。按以下优先原则
//  如果前面已经有桶，就不用管了。
//  如果前面没放桶，说明现在要放一个桶。那么我们肯定放后面，因为这样可以接后面的水
//  如果后面的位置不空，那么就只能放前面
//  如果前面也不空，就没办法了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumBuckets(string street) {
        int n = street.size();
        int vis[n];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            if (street[i] == '.') continue;
            if (i - 1 >= 0 && vis[i - 1]) continue;
            if (i + 1 < n && street[i + 1] == '.') {
                vis[i + 1] = 1;
                continue;
            }
            if (i - 1 >= 0 && street[i - 1] == '.') {
                vis[i - 1] = 1;
                continue;
            }
            return -1;
        }
        int res = 0;
        for (int i = 0; i < n; i++) res += vis[i];
        return res;
    }
};
