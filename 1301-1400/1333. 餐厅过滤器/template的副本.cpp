//
//  main.cpp
//  似乎先排序再过滤比先过滤再排序好一点
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> res;
        sort(restaurants.begin(), restaurants.end(), [](auto &a, auto &b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] > b[1];
        });
        for (int i = 0; i < restaurants.size(); i++) {
            auto &v = restaurants[i];
            if ((!veganFriendly || v[2]) && v[3] <= maxPrice && v[4] <= maxDistance) {
                res.push_back(v[0]);
            }
        }
        return res;
    }
};
