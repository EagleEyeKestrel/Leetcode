//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char c: moves) {
            if (c == 'L') x--;
            if (c == 'R') x++;
            if (c == 'U') y++;
            if (c == 'D') y--;
        }
        return !x && !y;
    }
};
