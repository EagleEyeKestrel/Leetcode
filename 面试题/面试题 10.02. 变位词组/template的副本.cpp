//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> v;
        for (string str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if (!mp.count(tmp)) {
                mp[tmp] = v.size();
                v.push_back({ str });
            } else {
                v[mp[tmp]].push_back(str);
            }
        }
        return v;
    }
};
