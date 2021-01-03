//
//  main.cpp
//  贪心，先拿单元多的箱子
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size(), res = 0, nowboxes = 0;
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b) {
            return a[1] > b[1];
        });
        for (int i = 0; i < n; i++) {
            int box = min(boxTypes[i][0], truckSize - nowboxes);
            res += box * boxTypes[i][1];
            nowboxes += box;
            if (!nowboxes) break;
        }
        return res;
    }
};
