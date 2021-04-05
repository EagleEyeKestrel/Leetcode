//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = coordinates[0] - 'a', y = coordinates[1] - '1';
        return x % 2 + y % 2 == 1;
    }
};
