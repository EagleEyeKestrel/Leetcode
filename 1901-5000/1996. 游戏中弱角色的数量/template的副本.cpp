//
//  main.cpp
//  实现的方法应该比较多。这里可以先对第一个字排序，然后要看右边最大的second值，预处理一下maxr
//  可以在first相同的情况下对second降序排序，这样可以确保first相等的不会被统计到
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size(), res = 0;
        sort(properties.begin(), properties.end(), [](auto &va, auto &vb) {
            if (va[0] == vb[0]) return va[1] > vb[1];
            return va[0] < vb[0];
        });
        int maxr[n];
        maxr[n - 1] = properties[n - 1][1];
        for (int i = n - 2; i >= 0; i--) {
            maxr[i] = max(maxr[i + 1], properties[i][1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            if (maxr[i + 1] > properties[i][1]) res++;
        }
        return res;
    }
};
