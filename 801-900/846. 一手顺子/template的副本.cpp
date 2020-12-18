//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if (n % W) return false;
        map<int, int> m;
        for (int num: hand) m[num]++;
        while (!m.empty()) {
            int start = m.begin()->first;
            for (int i = 0; i < W; i++) {
                int val = start + i;
                if (m.find(val) != m.end()) {
                    m[val]--;
                    if (m[val] == 0) m.erase(val);
                } else return false;
            }
        }
        return true;
    }
};
