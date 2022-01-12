//
//  main.cpp
//  比较简单的模拟
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int now = capacity, res = 0;
        for (int i = 0; i < n; i++) {
            res++;
            now -= plants[i];
            if (i < n - 1 && now < plants[i + 1]) {
                res += 2 * (i + 1);
                now = capacity;
            }
        }
        return res;
    }
};
