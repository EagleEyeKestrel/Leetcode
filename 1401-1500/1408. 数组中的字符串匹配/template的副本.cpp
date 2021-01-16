//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
