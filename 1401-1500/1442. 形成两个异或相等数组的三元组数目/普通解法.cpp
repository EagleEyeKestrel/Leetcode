//
//  main.cpp
//  穷举法，类似于中心扩散
//  穷举j，然后遍历k，记录下所有异或和出现的次数，然后再遍历i，遍历的同时更新res
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(),res = 0;
        for(int j = 2; j <= n; j++) {
            unordered_map<int, int> m;
            int now = 0;
            for(int k = j; k <= n; k++) {
                now = now ^ arr[k - 1];
                m[now]++;
            }
            now = 0;
            for(int i = j - 1; i >= 1; i--) {
                now = now ^ arr[i - 1];
                if(m[now]) res += m[now];
            }
        }
        return res;
    }
};
