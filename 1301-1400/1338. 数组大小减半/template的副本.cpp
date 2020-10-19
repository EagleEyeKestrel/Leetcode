//
//  main.cpp
//  cnt统计出所有元素出现次数，然后a直接放进去所有次数
//  次数从大到小排序，遍历，超过一半就break
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size(), now = 0, tmp = 0, res = 0, i = 0;
        int cnt[100010], a[100010];
        memset(cnt, 0, sizeof(cnt));
        for(int x: arr) cnt[x]++;
        for(int i = 1; i <= 1e5; i++) {
            if(cnt[i]) {
                a[now++] = cnt[i];
            }
        }
        sort(a, a + now, greater<int>());
        while(tmp < n / 2) {
            tmp += a[i++];
            res++;
        }
        return res;
    }
};
