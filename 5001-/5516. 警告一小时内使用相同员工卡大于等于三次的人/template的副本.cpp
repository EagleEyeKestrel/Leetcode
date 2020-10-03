//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<string>> m;
        int n = keyName.size();
        for(int i = 0; i < n; i++) {
            m[keyName[i]].push_back(keyTime[i]);
        }
        vector<string> res;
        for(auto it = m.begin(); it != m.end(); it++) {
            string name = it->first;
            vector<string> t = it->second;
            sort(t.begin(), t.end());
            if(t.size() >= 3) {
                for(int i = 2; i < t.size(); i++) {
                    string from = t[i - 2], to = t[i];
                    int h1 = (from[0] - '0') * 10 + from[1] - '0', m1 = (from[3] - '0') * 10 + from[4] - '0';
                    int h2 = (to[0] - '0') * 10 + to[1] - '0', m2 = (to[3] - '0') * 10 + to[4] - '0';
                    int d = 60 * (h2 - h1) + m2 - m1;
                    if(d <= 60) {
                        res.push_back(name);
                        break;
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
