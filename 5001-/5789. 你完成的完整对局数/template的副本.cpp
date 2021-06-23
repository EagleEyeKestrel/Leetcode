//
//  main.cpp
//  按题意舍入一下就好了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int h1 = stoi(startTime.substr(0, 2)), m1 = stoi(startTime.substr(3, 2));
        int h2 = stoi(finishTime.substr(0, 2)), m2 = stoi(finishTime.substr(3, 2));
        if (h2 < h1 || h1 == h2 && m2 < m1) h2 += 24;
        if (m1 % 15) m1 = (m1 / 15 + 1) * 15;
        if (m2 % 15) m2 = m2 / 15 * 15;
        return (60 * h2 + m2 - (60 * h1 + m1)) / 15;
    }
};
