//
//  main.cpp
//  约瑟夫问题，用vector做很方便
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;
        for (int i = 1; i <= n; i++) v.push_back(i);
        int now = -1;
        while (v.size() > 1) {
            int nextPos = (now + k) % v.size();
            v.erase(v.begin() + nextPos);
            now = (nextPos - 1 + v.size()) % v.size();
        }
        return v[0];
    }
};
