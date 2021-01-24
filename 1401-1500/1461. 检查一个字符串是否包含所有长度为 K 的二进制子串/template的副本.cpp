//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> se;
        int n = s.size();
        for (int i = 0; i <= n - k; i++) {
            se.insert(s.substr(i, k));
        }
        return se.size() == (1 << k);
    }
};
