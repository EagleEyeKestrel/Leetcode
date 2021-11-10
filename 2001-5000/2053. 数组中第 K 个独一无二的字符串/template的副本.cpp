//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (auto &s: arr) mp[s]++;
        int cnt = 0;
        for (auto &s: arr) {
            if (mp[s] == 1) cnt++;
            if (cnt == k) return s;
        }
        return "";
    }
};
