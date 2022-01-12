//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countPoints(string rings) {
        set<char> s[10];
        for (int i = 0; i < rings.size(); i += 2) {
            int id = rings[i + 1] - '0';
            s[id].insert(rings[i]);
        }
        int res = 0;
        for (int i = 0; i < 10; i++) {
            if (s[i].size() == 3) res++;
        }
        return res;
    }
};
