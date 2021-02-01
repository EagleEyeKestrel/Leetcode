//
//  main.cpp
//  比赛时的思路：找到第一个数，因为第一个数只会出现一次
//  对数之间建立索引，依次放下一个数就行了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1, start;
        unordered_map<int, vector<int>> mp;
        for (auto &v: adjacentPairs) {
            mp[v[0]].push_back(v[1]);
            mp[v[1]].push_back(v[0]);
        }
        for (auto it: mp) {
            if (it.second.size() == 1) {
                start = it.first;
                break;
            }
        }
        vector<int> res(n);
        res[0] = start;
        for (int i = 1; i < n; i++) {
            auto next = mp[res[i - 1]];
            if (next.size() == 1) res[i] = next[0];
            else {
                if (i >= 2 && next[0] == res[i - 2]) {
                    res[i] = next[1];
                } else {
                    res[i] = next[0];
                }
            }
        }
        return res;
        
    }
};
