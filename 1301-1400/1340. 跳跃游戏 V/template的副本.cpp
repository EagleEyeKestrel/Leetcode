//
//  main.cpp
//  看起来很难，其实就按照元素大小排序，然后从低到高处理即可，复杂度要求不高，n2就可以了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size(), ans = 0;
        vector<int> v;
        for (int i = 0; i < n; i++) v.push_back(i);
        sort(v.begin(), v.end(), [&](int x, int y) {
            if (arr[x] == arr[y]) return x < y;
            return arr[x] < arr[y];
        });
        int res[n];
        for (int i = 0; i < n; i++) res[i] = 1;
        for (int i = 0; i < n; i++) {
            int id = v[i], maxd = 0;
            for (int j = id + 1; j < n && j <= id + d; j++) {
                if (arr[j] >= arr[id]) break;
                maxd = max(maxd, res[j]);
            }
            for (int j = id - 1; j >= 0 && j >= id - d; j--) {
                if (arr[j] >= arr[id]) break;
                maxd = max(maxd, res[j]);
            }
            res[id] = maxd + 1;
            ans = max(ans, res[id]);
        }
        return ans;
    }
};
