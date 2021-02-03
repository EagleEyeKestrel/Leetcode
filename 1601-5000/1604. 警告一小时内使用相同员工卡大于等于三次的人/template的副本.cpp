//
//  main.cpp
//  每个人对应一个时间的列表，时间可以直接用数字表示
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        vector<string> res;
        unordered_map<string, vector<int>> mp;
        int n = keyName.size();
        for (int i = 0; i < n; i++) {
            string t = keyTime[i];
            int hour = stoi(t.substr(0, 2)), minute = stoi(t.substr(3, 2));
            mp[keyName[i]].push_back(hour * 60 + minute);
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            sort(it->second.begin(), it->second.end());
        }
        for (auto it: mp) {
            for (int i = 0; i < it.second.size() - 2; i++) {
                if (it.second[i + 2] - it.second[i] <= 60) {
                    res.push_back(it.first);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
