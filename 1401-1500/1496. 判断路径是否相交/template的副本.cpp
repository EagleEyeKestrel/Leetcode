//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        unordered_set<int> s;
        s.insert(0);
        for (char c: path) {
            if (c == 'N') y++;
            if (c == 'E') x++;
            if (c == 'S') y--;
            if (c == 'W') x--;
            if (s.count(1001 * x + y)) return true;
            s.insert(1001 * x + y);
        }
        return false;
    }
};
